//
//  Keyboard.cpp
//  platform
//
//  Created by BEPID on 11/18/16.
//
//

#include "Keyboard.h"

Keyboard& Keyboard::instance(){
    static Keyboard key;
    return key;
}

void Keyboard::onPress(int key){
    pressed[key] = true;
}

void Keyboard::onRelease(int key){
    pressed[key] = false;
}

bool Keyboard::isPressed(int key){
    if(pressed.find(key) == pressed.end()) return false;
    return pressed[key];
}