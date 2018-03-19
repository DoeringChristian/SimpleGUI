#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include "guiobject.h"

typedef unsigned int uint;

enum ButtonState{
    NORMAL,
    PRESSED,
    HOVERED
};

struct Button : public GUIObject{
    sf::Vector2f position;
    sf::Vector2f size;
    bool is_pressed;
    bool is_toggle;
    ButtonState state;
    sf::Color normal_inner_color;
    sf::Color hovered_inner_color;
    sf::Color pressed_inner_color;
    sf::Color normal_outer_color;
    sf::Color hovered_outer_color;
    sf::Color pressed_outer_color;
    sf::Color normal_text_color;
    sf::Color hovered_text_color;
    sf::Color pressed_text_color;
    sf::Text text;
    sf::RectangleShape displayed_shape;
    sf::Font font;
    uint indent;
    uint outline_thickness;
    
    
    void (*on_click)(GUIObject *);
    void (*on_release)(GUIObject *);
    
    Button();
    Button(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size, void (*on_click)(GUIObject *) = 0);

    //getters
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    ButtonState getState() const;
    sf::Color getNormalInnerColor() const;
    sf::Color getHoveredInnerColor() const;
    sf::Color getPressedInnerColor() const;
    sf::Color getNormalOuterColor() const;
    sf::Color getHoveredOuterColor() const;
    sf::Color getPressedOuterColor() const;
    sf::Color getNormalTextColor() const;
    sf::Color getHoveredTextColor() const;
    sf::Color getPressedTextColor() const;
    sf::Text getText() const;
    sf::Font getFont() const;
    uint getIndent() const;
    uint getOutlineThikness() const;
    Action getOnClick() const;
    Action getOnRelease() const;
    
    //setters
    void setPosition(const sf::Vector2f position);
    void setSize(const sf::Vector2f size);
    void setNormalInnerColor(const sf::Color color);
    void setHoveredInnerColor(const sf::Color color);
    void setPressedInnerColor(const sf::Color color);
    void setNormalOuterColor(const sf::Color color);
    void setHoveredOuterColor(const sf::Color color);
    void setPressedOuterColor(const sf::Color color);
    void setNormalTextColor(const sf::Color color);
    void setHoveredTextColor(const sf::Color color);
    void setPressedTextColor(const sf::Color color);
    void setText(const std::string text);
    void setText(const sf::Text text);
    void setFont(const std::string load_from);
    void setFont(const sf::Font font);
    void setIndent(uint indent);
    void setOutlineThickness(uint outline_thickness);
    void setFontSize(uint size);
    void setOnClick(const Action click);
    void setOnRelease(const Action release);
    void setToggle(const bool is_toggle);
    
    void update(sf::Event &event);
};

#endif // BUTTON_H
