#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "button.h"
#include "simplegui.h"

using namespace std;
using namespace sf;

RenderWindow window(VideoMode(800,600), "SFML", sf::Style::None);

void close(GUIObject *object){
    object->getWindow()->close();
}

int main(){
    window.setFramerateLimit(60);
    Event event;
    Clock frameClock;
    float frameTime;
    
    SimpleGUI gui(window);
    WindowMover mover(window, Vector2f(0,0), Vector2f(784,16));
    TextLabel label(window, Vector2f(50,10), 50);
    TextField field(window, Vector2f(100,100), Vector2f(300,50));
    Button b(window, Vector2f(window.getSize().x-16,1), Vector2f(15,15));
    b.setOnRelease(close);
    b.setPressedInnerColor(sf::Color::Red);
    b.setHoveredInnerColor(sf::Color::Red);
    b.setHoveredOuterColor(sf::Color::Blue);
    b.setNormalOuterColor(sf::Color::Black);
    b.setText("X");
    b.setFontSize(10);
    b.setToggle(true);
    label.setText("Write:");
    label.setTextColor(sf::Color::White);
    gui.add(mover);
    gui.add(label);
    gui.add(field);
    gui.add(b);
    
    makeWindowTransparent(window);
    while(window.isOpen()){
        event = Event();
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }
        frameTime = frameClock.getElapsedTime().asMilliseconds();
        frameClock.restart();
        setWindowAlpha(window, 100);
        window.clear(sf::Color(0,0,0,0));
        gui.update(event);
        window.display();
    }
    return 0;
}
