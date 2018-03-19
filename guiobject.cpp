#include "guiobject.h"

sf::RenderWindow *GUIObject::getWindow() const{
    return this->window;
}

void GUIObject::setVisible(const bool is_visible){
    this->is_visible = is_visible;
}

bool GUIObject::getVisible() const{
    return is_visible;
}
