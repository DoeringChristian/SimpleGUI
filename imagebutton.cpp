#include "imagebutton.h"


ImageButton::ImageButton(){
    this->is_pressed = false;
    this->is_viewed = false;
    this->is_visible = true;
    this->on_click = 0;
    this->on_release = 0;
    this->window = 0;
    this->state = NORMAL;
}

ImageButton::ImageButton(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size, std::string image){
    this->window = &window;
    this->position = position;
    this->size = size;
    this->texture_normal.loadFromFile(image);
    this->texture_hovered.loadFromFile(image);
    this->texture_pressed.loadFromFile(image);
    
    this->is_pressed = false;
    this->is_viewed = false;
    this->is_visible = true;
    this->on_click = 0;
    this->on_release = 0;
    this->state = NORMAL;
}

void ImageButton::update(sf::Event &event){
    if(sf::Mouse::getPosition(*window).x > this->position.x
            && sf::Mouse::getPosition(*window).x < this->position.x+this->size.x
            && sf::Mouse::getPosition(*window).y > this->position.y
            && sf::Mouse::getPosition(*window).y < this->position.y+this->size.y){
        this->state = HOVERED;
    }
    else
        this->state = NORMAL;
    if(this->state == HOVERED && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        this->state = PRESSED;
    
    if(this->state == PRESSED && !is_pressed && this->on_click != 0){
        on_click(this);
    }
    else if((this->state == NORMAL || this->state == HOVERED)
            && is_pressed && this->on_release != 0){
        on_release(this);
    }
    
    this->is_pressed = (this->state == PRESSED);
    
    //draw
    switch (state) {
    case NORMAL:
        this->sprite.setTexture(texture_normal);
        this->sprite.setPosition(position);
        this->sprite.setScale(size.x/texture_normal.getSize().x, size.y/texture_normal.getSize().y);
        break;
    case HOVERED:
        this->sprite.setTexture(texture_hovered);
        this->sprite.setPosition(position);
        this->sprite.setScale(size.x/texture_hovered.getSize().x, size.y/texture_hovered.getSize().y);
        break;
    case PRESSED:
        this->sprite.setTexture(texture_pressed);
        this->sprite.setPosition(position);
        this->sprite.setScale(size.x/texture_pressed.getSize().x, size.y/texture_pressed.getSize().y);
        break;
    }
    this->window->draw(sprite);
    
}

sf::Vector2f ImageButton::getPosition() const{
    return position;
}

sf::Vector2f ImageButton::getSize() const{
    return size;
}

Action ImageButton::getOnClick() const{
    return on_click;
}

Action ImageButton::getOnRelease() const{
    return on_release;
}

void ImageButton::loadTexture(std::string file){
    this->texture_normal.loadFromFile(file);
    this->texture_hovered.loadFromFile(file);
    this->texture_pressed.loadFromFile(file);
}

void ImageButton::loadTextureNormal(std::string file){
    this->texture_normal.loadFromFile(file);
}

void ImageButton::loadTextureHovered(std::string file){
    this->texture_hovered.loadFromFile(file);
}

void ImageButton::loadTexturePressed(std::string file){
    this->texture_pressed.loadFromFile(file);
}

void ImageButton::setPosition(sf::Vector2f position){
    this->position = position;
}

void ImageButton::setSize(sf::Vector2f size){
    this->size = size;
}

void ImageButton::setOnClick(const Action click){
    this->on_click = click;
}

void ImageButton::setOnRelease(const Action release){
    this->on_release = release;
}












