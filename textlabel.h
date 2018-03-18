#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include "guiobject.h"

typedef unsigned int uint;

struct TextLabel : public GUIObject{
    sf::Vector2f position;
    uint font_size;
    sf::Color text_color;
    sf::Text text;
    sf::Font font;
    
    TextLabel();
    TextLabel(sf::RenderWindow &window, sf::Vector2f position, uint font_size);
    
    void update(sf::Event &event);
    
    //getters
    sf::Vector2f getPosition() const;
    sf::Color getTextColor() const;
    sf::Text getText() const;
    
    //setters
    void setPosition(const sf::Vector2f position);
    void setTextColor(const sf::Color color);
    void setText(const sf::Text text);
    void setText(const std::string text);
    void loadFont(const std::string file);
};

#endif // TEXTLABEL_H
