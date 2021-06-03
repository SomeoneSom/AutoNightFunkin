/* keypresser:
virtually presses keys
members ending in '__' should be seen as "private"*/
#include <windows.h>
#ifndef KEYPRESSER_HPP
#define KEYPRESSER_HPP
namespace KeyPresser {
    class KeyPresser {
        private:
            void keyDown__(WORD key);
            void keyUp__(WORD key);
            INPUT virtKeyboard__;
        public:
            KeyPresser();
            void pressKey(WORD key);
            void holdKey(WORD key, DWORD milliseconds);
    };
}
#endif