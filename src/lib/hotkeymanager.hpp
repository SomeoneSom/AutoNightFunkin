/* hotkeymanager:
sets hotkeys with global hooks and sets callbacks for those hotkeys 
members ending in '__' should be seen as "private"*/
#include <windows.h>
#include <iostream>
#include <vector>
#ifndef HOTKEYMANAGER_HPP
#define HOTKEYMANAGER_HPP
namespace HotkeyManager {
    typedef struct CallbackThing {
        int (* funcToCall)();
        int keyCode;
    } CallbackThing;
    BOOL CALLBACK ctrlCHandler__(DWORD);
    extern std::vector<CallbackThing> allTheCallbacks;
    int init();
    LRESULT CALLBACK callbackKing__(int code, WPARAM w, LPARAM l);
    extern bool alreadyDown__;
    extern HHOOK kbHook__;
    int loopThing();
};
#endif