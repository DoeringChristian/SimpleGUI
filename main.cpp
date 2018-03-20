#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "button.h"
#include "simplegui.h"

#define QUESTION_AMMOUNT 10

using namespace std;
using namespace sf;

typedef unsigned int uint;

RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML", sf::Style::Fullscreen);

uint state = 0;

void wrongAnswer(GUIObject *object){
    state = 0;
}

void rightAnswer(GUIObject *object){
    if(state < QUESTION_AMMOUNT)
        state++;
}

void close(GUIObject *object){
    object->getWindow()->close();
}

int main(){
    sf::Vector2f button_positions[4];
    button_positions[0] = sf::Vector2f(window.getSize().x/16*1, 
                                       window.getSize().y/18*12);
    button_positions[1] = sf::Vector2f(window.getSize().x/16*9, 
                                       window.getSize().y/18*12);
    button_positions[2] = sf::Vector2f(window.getSize().x/16*1, 
                                       window.getSize().y/18*15);
    button_positions[3] = sf::Vector2f(window.getSize().x/16*9, 
                                       window.getSize().y/18*15);
    
    
    window.setFramerateLimit(60);
    Event event;
    Clock frameClock;
    float frameTime;
    
    SimpleGUI gui(window);
    
#if 1
    ImageButton ib(window, sf::Vector2f(0,0), sf::Vector2f(50,50), "Logo.png");
    ib.loadTexturePressed("Logo01.png");
    ib.setOnRelease(close);
    gui.add(ib);
#endif
    
    Button answers[QUESTION_AMMOUNT][4];
    for(uint i = 0;i < QUESTION_AMMOUNT;i++){
        for(uint j = 0;j < 4;j++){
            answers[i][j] = Button(window, sf::Vector2f(0,0), sf::Vector2f(0,0));
            answers[i][j].setVisible(false);
            answers[i][j].setPosition(button_positions[j]);
            answers[i][j].setNormalInnerColor(sf::Color::Green);
            answers[i][j].setNormalOuterColor(sf::Color::Cyan);
            answers[i][j].setNormalTextColor(sf::Color::Black);
            answers[i][j].setHoveredInnerColor(sf::Color::Red);
            answers[i][j].setHoveredOuterColor(sf::Color::Green);
            answers[i][j].setHoveredTextColor(sf::Color::Black);
            answers[i][j].setPressedInnerColor(sf::Color::Green);
            answers[i][j].setPressedOuterColor(sf::Color::Cyan);
            answers[i][j].setPressedTextColor(sf::Color::Black);
            answers[i][j].setSize(sf::Vector2f(window.getSize().x/16*6, 
                                               window.getSize().y/18*2));
            gui.add(answers[i][j]);
        }
    }
    
    answers[0][0].setOnRelease(rightAnswer);
    answers[0][1].setOnRelease(wrongAnswer);
    answers[0][2].setOnRelease(wrongAnswer);
    answers[0][3].setOnRelease(wrongAnswer);
    
    answers[1][0].setOnRelease(rightAnswer);
    answers[1][1].setOnRelease(wrongAnswer);
    answers[1][2].setOnRelease(wrongAnswer);
    answers[1][3].setOnRelease(wrongAnswer);
    
    answers[2][0].setOnRelease(rightAnswer);
    answers[2][1].setOnRelease(wrongAnswer);
    answers[2][2].setOnRelease(wrongAnswer);
    answers[2][3].setOnRelease(wrongAnswer);
    
    answers[3][0].setOnRelease(rightAnswer);
    answers[3][1].setOnRelease(wrongAnswer);
    answers[3][2].setOnRelease(wrongAnswer);
    answers[3][3].setOnRelease(wrongAnswer);
    
    answers[4][0].setOnRelease(rightAnswer);
    answers[4][1].setOnRelease(wrongAnswer);
    answers[4][2].setOnRelease(wrongAnswer);
    answers[4][3].setOnRelease(wrongAnswer);
    
    answers[5][0].setOnRelease(rightAnswer);
    answers[5][1].setOnRelease(wrongAnswer);
    answers[5][2].setOnRelease(wrongAnswer);
    answers[5][3].setOnRelease(wrongAnswer);
    
    answers[6][0].setOnRelease(rightAnswer);
    answers[6][1].setOnRelease(wrongAnswer);
    answers[6][2].setOnRelease(wrongAnswer);
    answers[6][3].setOnRelease(wrongAnswer);
    
    answers[7][0].setOnRelease(rightAnswer);
    answers[7][1].setOnRelease(wrongAnswer);
    answers[7][2].setOnRelease(wrongAnswer);
    answers[7][3].setOnRelease(wrongAnswer);
    
    answers[8][0].setOnRelease(rightAnswer);
    answers[8][1].setOnRelease(wrongAnswer);
    answers[8][2].setOnRelease(wrongAnswer);
    answers[8][3].setOnRelease(wrongAnswer);
    
    answers[9][0].setOnRelease(rightAnswer);
    answers[9][1].setOnRelease(wrongAnswer);
    answers[9][2].setOnRelease(wrongAnswer);
    answers[9][3].setOnRelease(wrongAnswer);
    
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
        if(state != 10)
            for(uint i = 0;i < QUESTION_AMMOUNT;i++){
                for(uint j = 0;j < 4;j++){
                    if(i == state)
                        answers[i][j].setVisible(true);
                    else
                        answers[i][j].setVisible(false);
                }
            }
        else
            window.close();
        
        setWindowAlpha(window, 255);
        makeWindowOnTop(window);
        window.clear(sf::Color(0,0,0,0));
        gui.update(event);
        window.display();
    }
    return 0;
}
