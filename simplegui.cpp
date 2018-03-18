#include "simplegui.h"


SimpleGUI::SimpleGUI(){
    this->window = 0;
}

SimpleGUI::SimpleGUI(sf::RenderWindow &window){
    this->window = &window;
}

void SimpleGUI::add(GUIObject &object){
    objects.push_back(&object);
}

void SimpleGUI::remove(GUIObject &object){
    for(uint i = 0;i < objects.size();i++)
        if(objects[i] == &object)
            objects.erase(objects.begin()+i);
}

void SimpleGUI::update(sf::Event &event){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        for(uint i = 0;i < objects.size();i++)
            objects[i]->is_viewed = false;
    for(uint i = 0;i < objects.size();i++)
        objects[i]->update(event);
}
