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
BOOL CALLBACK HotkeyManager::ctrlCHandler__(DWORD) {
    PostThreadMessage(GetCurrentThreadId(), WM_QUIT, 0, 0);
    return TRUE;
}
int HotkeyManager::init() {
    SetConsoleCtrlHandler(&ctrlCHandler__, TRUE);
    kbHook__ = SetWindowsHookEx(WH_KEYBOARD_LL, &callbackKing__, GetModuleHandle(NULL), 0);
    if (kbHook__ == NULL) {
        std::cout << "SetWindowsHookEx failed with error " << GetLastError() << std::endl;
        return 1;
    }
    return 0;
}
int HotkeyManager::loopThing() {
    MSG msg;
    if (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        return 0;
    } else {
        UnhookWindowsHookEx(kbHook__);
        return 1;
    }
}
LRESULT CALLBACK HotkeyManager::callbackKing__(int code, WPARAM w, LPARAM l) {
    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)l;
    if (w == WM_KEYDOWN && alreadyDown__) {
        alreadyDown__ = true;
        for (int i = 0; i < allTheCallbacks.size(); i++) {
            if (allTheCallbacks.at(i).keyCode == p->vkCode) {
                allTheCallbacks.at(i).funcToCall();
            }
        }
    } else if (w == WM_KEYUP) {
        alreadyDown__ = false;
    }
    return CallNextHookEx(kbHook__, code, w, l);
}