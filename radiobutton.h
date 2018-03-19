#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include "guiobject.h"

struct RadioButton : public GUIObject{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Text text;
    sf::Font font;
    
};

#endif // RADIOBUTTON_H
