#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include "guiobject.h"
#include "button.h"

struct ImageButton : GUIObject{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture texture_normal;
    sf::Texture texture_hovered;
    sf::Texture texture_pressed;
    sf::Sprite sprite;
    ButtonState state;
    bool is_pressed;
    
    void (*on_click)(GUIObject *);
    void (*on_release)(GUIObject *);
    
    ImageButton();
    ImageButton(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size, std::string image);
    
    void update(sf::Event &event);
    
    //getters
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    Action getOnClick() const;
    Action getOnRelease() const;
    
    //setters
    void loadTexture(std::string file);
    void loadTextureNormal(std::string file);
    void loadTextureHovered(std::string file);
    void loadTexturePressed(std::string file);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setOnClick(const Action click);
    void setOnRelease(const Action release);
        
};

#endif // IMAGEBUTTON_H
