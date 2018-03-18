#ifndef WINDOWMOVER_H
#define WINDOWMOVER_H

#include "guiobject.h"

typedef unsigned int uint;

struct WindowMover : public GUIObject{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2i mouse_position;
    sf::Color inner_color;
    sf::Color outer_color;
    sf::RectangleShape display_shape;
    bool is_pressed, is_pressed_befor;
    
    WindowMover();
    WindowMover(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size);
    
    void update(sf::Event &event);
};

#endif // WINDOWMOVER_H
