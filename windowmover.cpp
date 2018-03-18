#include "windowmover.h"


WindowMover::WindowMover(){
    this->window = 0;
    this->inner_color = sf::Color::Black;
    this->outer_color = sf::Color::Blue;
    this->is_pressed = false;
    this->is_pressed_befor = false;
}

WindowMover::WindowMover(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size){
    this->window = &window;
    this->position = position;
    this->size = size;
    this->inner_color = sf::Color::Black;
    this->outer_color = sf::Color::Blue;
    this->display_shape.setOutlineThickness(1);
    this->is_pressed = false;
    this->is_pressed_befor = false;
}

void WindowMover::update(sf::Event &event){
    this->display_shape.setPosition(position);
    this->display_shape.setSize(size);
    this->display_shape.setOutlineColor(outer_color);
    this->display_shape.setFillColor(inner_color);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(sf::Mouse::getPosition(*window).x > this->position.x
                && sf::Mouse::getPosition(*window).x < this->position.x+this->size.x
                && sf::Mouse::getPosition(*window).y > this->position.y
                && sf::Mouse::getPosition(*window).y < this->position.y+this->size.y){
            this->is_pressed = true;
            if(is_pressed && !is_pressed_befor)
                this->mouse_position = sf::Mouse::getPosition(*window);
        }
        
    }
    else
        is_pressed = false;
    if(is_pressed)
        window->setPosition(sf::Mouse::getPosition()-mouse_position);
    
    this->is_pressed_befor = is_pressed;
    window->draw(display_shape);
}
