#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "../../Theme/Colors.h"

class SVisu
{
private:
    std::vector<int> vec_;
    std::vector<sf::RectangleShape> rectangles_; // array for the rectangles representing each vec_ element

public:
    SVisu();

    void populateVec(int smallestN, int largestN, int size);

    std::vector<int>& getVec();
    int getVecMaxVal();

    void createRectangles(sf::Vector2u resolution);
    std::vector<sf::RectangleShape>& getRectangles();

    // for debug purposes:

    void printVec(); 
    void printRects();
};