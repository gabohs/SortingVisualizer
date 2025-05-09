#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "../Visualizer/SVisu.h"
#include "../../Theme/Colors.h"

class App
{
private:
    sf::RenderWindow window_;
    sf::Vector2u resolution_;
    SVisu sVisualizer_;
    
    void input();
    void update();
    void draw();

public:
    App();

    void run();
};
