#include "SVisu.h"

SVisu::SVisu()
{
}

void SVisu::populateVec(int smallestN, int largestN, int size)
{
    for (int i = 0; i < size; i++)
    {
        vec_.push_back(std::rand() % largestN +smallestN);
    }
}

void SVisu::createRectangles(sf::Vector2u resolution)
{
    int maxVal = *std::max_element(vec_.begin(), vec_.end()); // get the max value in the vector, for value mapping


     // populate rectangles_, the vector used to represent vec_ values as rectangles on the screen
    for (int i = 0; i < vec_.size(); i++)
    {   
        float rWidth = static_cast<float>(resolution.x) / vec_.size();  // width of each rectangle
        float rHeight = static_cast<float>(vec_[i]) / maxVal * resolution.y;

        sf::RectangleShape rect;

        sf::Vector2f size = {rWidth, rHeight};

        sf::Vector2f pos = { ( i * size.x ), ( static_cast<float>(resolution.y) - size.y ) };

        rect.setSize(size);

        if (i % 2 == 0)
        {
            rect.setFillColor(Colors::Rectangles_1);
        }
        else
        {
            rect.setFillColor(Colors::Rectangles_2);
        }

        rect.setPosition(pos);

        rectangles_.push_back(rect);
    }
}

const std::vector<sf::RectangleShape>& SVisu::getRectangles()
{
    return rectangles_;
}

void SVisu::printVec()
{
    for (int e : vec_)
    {
        std::cout << e << " "; 
    }
    std::cout << std::endl;
}

void SVisu::printRects()
{
    for (auto r : rectangles_)
    {
        std::cout << "(" << r.getPosition().x << " , " << r.getPosition().y << ")" << "   "; 
    }
    std::cout << std::endl;
}
