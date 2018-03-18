TEMPLATE = app
CONFIG += console c++98
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    button.cpp \
    guiobject.cpp \
    simplegui.cpp \
    textfield.cpp \
    textlabel.cpp \
    windowmover.cpp

DEFINES += SFML_STATIC

LIBS += -static

LIBS += -LC:/SFML-2.1/lib

INCLUDEPATH += C:/SFML-2.1/include
DEPENDPATH += C:/SFML-2.1/include

LIBS += -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d -lsfml-network-s-d -lsfml-audio-s-d

HEADERS += \
    button.h \
    guiobject.h \
    simplegui.h \
    textfield.h \
    textlabel.h \
    windowmover.h
