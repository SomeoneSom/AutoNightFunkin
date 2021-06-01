/* hotkeymanager:
sets hotkeys with global hooks and sets callbacks for those hotkeys 
members ending in '__' should be seen as "private"*/
#include "lib/hotkeymanager.hpp"
#include <vector>
#include <windows.h>
#include <iostream>
std::vector<HotkeyManager::CallbackThing> HotkeyManager::allTheCallbacks = {};
bool HotkeyManager::alreadyDown__ = false;
HHOOK HotkeyManager::kbHook__ = 0;
int HotkeyManager::loopThing() {
    bool temp = false;
    for (int i = 0; i < allTheCallbacks.size(); i++) {
        if ((1 << 15) & GetAsyncKeyState(allTheCallbacks.at(i).keyCode)) {
            temp = true;
            if (!alreadyDown__) {
                allTheCallbacks.at(i).funcToCall();
            }
        }
    }
    alreadyDown__ = temp;
    return 0;
}