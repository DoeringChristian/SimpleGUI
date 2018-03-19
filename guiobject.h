#ifndef GUIOBJECT_H
#define GUIOBJECT_H

#include <SFML/Graphics.hpp>

struct GUIObject{
    sf::RenderWindow *window;
public:
    bool is_viewed;
    bool is_visible;
    
    virtual void update(sf::Event &event) = 0;
    sf::RenderWindow *getWindow() const;
    
    void setVisible(const bool is_visible);
    
    bool getVisible() const;
};

typedef void (*Action)(GUIObject *);

#endif // GUIOBJECT_H
