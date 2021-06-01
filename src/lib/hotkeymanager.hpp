/* hotkeymanager:
sets hotkeys with global hooks and sets callbacks for those hotkeys 
members ending in '__' should be seen as "private"*/
#include <windows.h>
#include <iostream>
#include <vector>
#include <thread>
#ifndef HOTKEYMANAGER_HPP
#define HOTKEYMANAGER_HPP
namespace HotkeyManager {
    typedef struct CallbackThing {
        int (* funcToCall)();
        int keyCode;
    } CallbackThing;
    extern std::vector<CallbackThing> allTheCallbacks;
    extern bool alreadyDown__;
    int loopThing();
};
#endif