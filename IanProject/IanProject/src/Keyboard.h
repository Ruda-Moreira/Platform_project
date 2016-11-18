//
//  Keyboard.h
//  platform
//
//  Created by BEPID on 11/18/16.
//
//

#ifndef Keyboard_h
#define Keyboard_h

#include <map>
#define KEYS Keyboard::instance()

using namespace std;

class Keyboard{
    private:
        map <int, bool> pressed;
        Keyboard(){}
    public:
        static Keyboard& instance();
        void onPress(int key);
        void onRelease(int key);
        bool isPressed(int key);
    
};


#endif /* Keyboard_h */
