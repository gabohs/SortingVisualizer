#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

#include "../Visualizer/SVisu.h"
#include "../../Theme/Colors.h"
#include "../SortingAlgorithms/Sorting.h"

class App
{
private:
    sf::RenderWindow window_;
    sf::Vector2u resolution_;
    SVisu sVisualizer_;
    
    void events();
    void update();
    void draw();

public:
    App();

    void run();
};
