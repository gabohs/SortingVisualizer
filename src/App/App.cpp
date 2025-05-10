#include "App.h"

App::App() 
{   
    std::srand(std::time(nullptr));

    resolution_ = sf::VideoMode::getDesktopMode().size;

    window_.create(sf::VideoMode(resolution_), "Sorting Algorithm Visualizer", sf::Style::Default, sf::State::Windowed);

    sVisualizer_.populateVec(50, 500, 50);
    sVisualizer_.createRectangles(resolution_);

    sVisualizer_.printVec();
}

void App::events()
{
    while (const std::optional event = window_.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window_.close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
    {
        window_.close();
    }

}

void App::update()
{   
    // Press enter to start sorting animation
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
    {
        Sorting::bubbleSort(sVisualizer_.getVec());

        for (size_t i = 0; i < sVisualizer_.getRectangles().size(); i++)
        {
            auto& currentRect = sVisualizer_.getRectangles()[i];
            float newHeight = static_cast<float>(sVisualizer_.getVec()[i]) / sVisualizer_.getVecMaxVal() * resolution_.y;

            currentRect.setSize({ currentRect.getSize().x, newHeight });
            currentRect.setPosition({ currentRect.getPosition().x, resolution_.y - newHeight });

            draw();
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
}

void App::draw()
{
    window_.clear(Colors::Background);

    for (auto& rect : sVisualizer_.getRectangles())
    {
        window_.draw(rect);
    }

    window_.display();
}

void App::run()
{
    while (window_.isOpen())
    {
        events();
        update();
        draw();
    }
}