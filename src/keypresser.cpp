/* keypresser:
virtually presses keys
members ending in '__' should be seen as "private"*/
#include "lib/keypresser.hpp"
#include <windows.h>
INPUT KeyPresser::virtKeyboard__;
void KeyPresser::setup() {
    virtKeyboard__.type = INPUT_KEYBOARD;
    virtKeyboard__.ki.wScan = 0;
    virtKeyboard__.ki.time = 0;
    virtKeyboard__.ki.dwExtraInfo = 0;
}
void KeyPresser::keyDown__(WORD key) {
    virtKeyboard__.ki.wVk = key;
    virtKeyboard__.ki.dwFlags = 0;
    SendInput(1, &virtKeyboard__, sizeof(INPUT));
}
void KeyPresser::keyUp__(WORD key) {
    virtKeyboard__.ki.wVk = key;
    virtKeyboard__.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &virtKeyboard__, sizeof(INPUT));
}
void KeyPresser::pressKey(WORD key) {
    keyDown__(key);
    keyUp__(key);
}
void KeyPresser::holdKey(WORD key, DWORD milliseconds) {
    keyDown__(key);
    Sleep(milliseconds);
    keyUp__(key);
}