#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "guiobject.h"
#include <iostream>

typedef unsigned int uint;

enum TextFieldType{
    ONE_LINE,
    MULTIBLE_LINES
};

struct TextField : public GUIObject{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color outer_color;
    sf::Color inner_color;
    sf::Color text_color;
    sf::Color cursor_color;
    uint cursor_width;
    uint font_size;
    sf::Text text;
    sf::Font font;
    sf::RectangleShape displayed_shape;
    sf::RectangleShape cursor;
    uint lines;
    TextFieldType type;
    
    TextField();
    TextField(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size);
    
    void update(sf::Event &event);
    
    //getters
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    sf::Color getOuterColor() const;
    sf::Color getInnerColor() const;
    sf::Color getTextColor() const;
    sf::Color getCursorColor() const;
    uint getCursorWidth() const;
    sf::Text getText() const;
    sf::String getString() const;
    sf::Font getFont() const;
    uint getFontSize() const;
    TextFieldType getType() const;
    
    //setters
    void setPosition(const sf::Vector2f position);
    void setSize(const sf::Vector2f size);
    void setOuterColor(const sf::Color color);
    void setInnerColor(const sf::Color color);
    void setTextColor(const sf::Color color);
    void setCursorColor(const sf::Color color);
    void setCursorWidth(uint width);
    void setText(const std::string text);
    void setText(const sf::Text text);
    void setFont(const sf::Font font);
    void loadFont(const std::string file);
    void setFontSize(const uint size);
    void setType(const TextFieldType type);
};

#endif // TEXTFIELD_H
