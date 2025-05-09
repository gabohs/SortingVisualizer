#include "App.h"

App::App() 
{   
    std::srand(std::time(nullptr));

    resolution_ = sf::VideoMode::getDesktopMode().size;

    window_.create(sf::VideoMode(resolution_), "Sorting Algorithm Visualizer", sf::Style::Default, sf::State::Windowed);

    sVisualizer_.populateVec(1, 50, 20);
    sVisualizer_.createRectangles(resolution_);

    sVisualizer_.printRects();
    sVisualizer_.printVec();
}

void App::input()
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
}

void App::draw()
{
    window_.clear(Colors::Background);

    for (const auto& rect : sVisualizer_.getRectangles())
    {
        window_.draw(rect);
    }

    window_.display();
}

void App::run()
{
    while (window_.isOpen())
    {
        input();
        update();
        draw();
    }
}