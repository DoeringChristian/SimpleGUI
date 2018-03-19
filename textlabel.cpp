#include "textlabel.h"


TextLabel::TextLabel(){
    this->window = 0;
    this->text_color = sf::Color::White;
    this->is_visible = true;
}

TextLabel::TextLabel(sf::RenderWindow &window, sf::Vector2f position, uint font_size){
    this->window = &window;
    this->position = position;
    this->font_size = font_size;
    this->font.loadFromFile("arial.ttf");
    this->text.setFont(font);
    this->is_visible = true;
}

void TextLabel::update(sf::Event &event){
    this->text.setPosition(position);
    this->text.setFont(font);
    this->text.setCharacterSize(font_size);
    this->text.setColor(text_color);
    
    window->draw(text);
}

sf::Vector2f TextLabel::getPosition() const{
    return position;
}

sf::Color TextLabel::getTextColor() const{
    return text_color;
}

sf::Text TextLabel::getText() const{
    return text;
}

void TextLabel::setPosition(const sf::Vector2f position){
    this->position = position;
}

void TextLabel::setTextColor(const sf::Color color){
    this->text_color = color;
}

void TextLabel::setText(const sf::Text text){
    this->text = text;
}

void TextLabel::setText(const std::string text){
    this->text.setString(text);
}

void TextLabel::loadFont(const std::string file){
    this->font.loadFromFile(file);
}
