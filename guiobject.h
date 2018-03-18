#ifndef GUIOBJECT_H
#define GUIOBJECT_H

#include <SFML/Graphics.hpp>

struct GUIObject{
    sf::RenderWindow *window;
public:
    bool is_viewed;
    
    virtual void update(sf::Event &event) = 0;
    sf::RenderWindow *getWindow() const;
};

#endif // GUIOBJECT_H
