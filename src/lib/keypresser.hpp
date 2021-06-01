/* keypresser:
virtually presses keys
members ending in '__' should be seen as "private"*/
#include <windows.h>
#ifndef KEYPRESSER_HPP
#define KEYPRESSER_HPP
namespace KeyPresser {
    extern INPUT virtKeyboard__;
    void setup();
    void pressKey(WORD key);
    void holdKey(WORD key, DWORD milliseconds);
    void keyDown__(WORD key);
    void keyUp__(WORD key);
}
#endif