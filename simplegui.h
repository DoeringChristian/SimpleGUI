#ifndef SIMPLEGUI_H
#define SIMPLEGUI_H

#include "guiobject.h"
#include "button.h"
#include <vector>
#include <windows.h>
#include "textfield.h"
#include "textlabel.h"
#include "windowmover.h"

struct SimpleGUI{
    sf::RenderWindow *window;
    std::vector <GUIObject*> objects;
    SimpleGUI();
    SimpleGUI(sf::RenderWindow &window);
    
    void add(GUIObject &object);
    void remove(GUIObject &object);
    
    void update(sf::Event &event);
};


inline void makeWindowTransparent(sf::RenderWindow& window){
        HWND hwnd = window.getSystemHandle();
        SetWindowLongPtr(hwnd, GWL_EXSTYLE, GetWindowLongPtr(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
}
inline void makeWindowOpaque(sf::RenderWindow& window){
        HWND hwnd = window.getSystemHandle();
        SetWindowLongPtr(hwnd, GWL_EXSTYLE, GetWindowLongPtr(hwnd, GWL_EXSTYLE) & ~WS_EX_LAYERED);
        RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_FRAME | RDW_ALLCHILDREN);
}
inline void setWindowAlpha(sf::RenderWindow& window, sf::Uint8 alpha = 255){
        SetLayeredWindowAttributes(window.getSystemHandle(), 0, alpha, LWA_ALPHA);
}

inline void makeWindowOnTop(sf::RenderWindow& window){
        HWND hwnd = window.getSystemHandle();
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
}

#endif // SIMPLEGUI_H
