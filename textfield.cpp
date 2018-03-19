#include "textfield.h"

TextField::TextField(){
    this->window = 0;
    this->inner_color = sf::Color::White;
    this->outer_color = sf::Color::Black;
    this->displayed_shape.setOutlineThickness(1);
    this->text_color = sf::Color::Black;
    this->is_viewed = false;
    this->cursor;
    this->cursor_color = sf::Color::Black;
    this->cursor_width = 1;
    this->lines = 0;
    this->type = ONE_LINE;
    this->is_visible = true;
}

TextField::TextField(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size){
    this->window = &window;
    this->position = position;
    this->size = size;
    this->cursor = sf::RectangleShape(sf::Vector2f(1,size.y-4));
    this->cursor.setOutlineThickness(0);
    this->cursor_color = sf::Color::Black;
    this->text_color = sf::Color::Black;
    this->inner_color = sf::Color::White;
    this->outer_color = sf::Color::Black;
    this->displayed_shape.setOutlineThickness(1);
    this->is_viewed = false;
    this->font.loadFromFile("arial.ttf");
    this->cursor_width = 1;
    this->font_size = size.y-4;
    this->lines = 0;
    this->type = ONE_LINE;
    this->is_visible = true;
}

void TextField::update(sf::Event &event){
    this->text.setFont(font);
    if(event.type == sf::Event::TextEntered && is_viewed){
        if(type == MULTIBLE_LINES){
            sf::String tmp_string = text.getString();
            sf::String tmp_string2 = text.getString();
            if((char)event.text.unicode == 0x08){
                if(tmp_string[tmp_string.getSize()-1] == '\n')
                    lines--;
                if(tmp_string.getSize() > 0)
                    tmp_string.erase(tmp_string.getSize()-1);
            }
            else
                tmp_string += (char)event.text.unicode;
            
            text.setString(tmp_string);
            
            if(text.getGlobalBounds().width > size.x){
                tmp_string2 += '\n';
                tmp_string2 += (char)event.text.unicode;
                lines++;
                text.setString(tmp_string2);
            }
        }
        else if(type == ONE_LINE){
            sf::String tmp_string = text.getString();
            sf::String tmp_string2 = text.getString();
            if((char)event.text.unicode == 0x08){
                if(tmp_string.getSize() > 0)
                    tmp_string.erase(tmp_string.getSize()-1);
            }
            else
                tmp_string += (char)event.text.unicode;
            text.setString(tmp_string);
            if(text.getGlobalBounds().width > size.x)
                text.setString(tmp_string2);
        }
    }
    
    if(sf::Mouse::getPosition(*window).x > this->position.x
            && sf::Mouse::getPosition(*window).x < this->position.x+this->size.x
            && sf::Mouse::getPosition(*window).y > this->position.y
            && sf::Mouse::getPosition(*window).y < this->position.y+this->size.y){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            this->is_viewed = true;
    }
    
    this->displayed_shape.setFillColor(inner_color);
    this->displayed_shape.setOutlineColor(outer_color);
    this->text.setColor(text_color);
    this->text.setCharacterSize(font_size);
    this->displayed_shape.setPosition(position);
    this->displayed_shape.setSize(size);
    this->cursor.setFillColor(cursor_color);
    this->text.setFont(font);
    this->text.setPosition(sf::Vector2f(position.x,position.y-text.getGlobalBounds().height/4));
    this->cursor.setPosition(sf::Vector2f(position.x+1+text.getGlobalBounds().width, position.y+2+(font_size+4)*lines));
    this->cursor.setSize(sf::Vector2f(cursor_width, font_size));
    
    window->draw(displayed_shape);
    if(is_viewed)
        window->draw(cursor);
    window->draw(text);
}

sf::Vector2f TextField::getPosition() const{
    return position;
}

sf::Vector2f TextField::getSize() const{
    return size;
}

sf::Color TextField::getOuterColor() const{
    return outer_color;
}

sf::Color TextField::getInnerColor() const{
    return inner_color;
}

sf::Color TextField::getTextColor() const{
    return text_color;
}

sf::Color TextField::getCursorColor() const{
    return cursor_color;
}

uint TextField::getCursorWidth() const{
    return cursor_width;
}

sf::Text TextField::getText() const{
    return text;
}

sf::String TextField::getString() const{
    return text.getString();
}

sf::Font TextField::getFont() const{
    return font;
}

uint TextField::getFontSize() const{
    return font_size;
}

TextFieldType TextField::getType() const{
    return type;
}

void TextField::setPosition(const sf::Vector2f position){
    this->position = position;
}

void TextField::setSize(const sf::Vector2f size){
    this->size = size;
}

void TextField::setOuterColor(const sf::Color color){
    this->outer_color = color;
}

void TextField::setInnerColor(const sf::Color color){
    this->inner_color = color;
}

void TextField::setTextColor(const sf::Color color){
    this->text_color = color;
}

void TextField::setCursorColor(const sf::Color color){
    this->cursor_color = color;
}

void TextField::setCursorWidth(uint width){
    this->cursor_width = width;
}

void TextField::setText(const std::string text){
    this->text.setString(text);
}

void TextField::setText(const sf::Text text){
    this->text = text;
}

void TextField::setFont(const sf::Font font){
    this->font = font;
}

void TextField::loadFont(const std::string file){
    this->font.loadFromFile(file);
}

void TextField::setFontSize(const uint size){
    this->font_size = size;
}

void TextField::setType(const TextFieldType type){
    this->type = type;
}
