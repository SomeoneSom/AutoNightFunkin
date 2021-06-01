/* theactualbot:
virtually presses keys but to the json
members ending in '__' should be seen as "private"*/
#include "keypresser.hpp"
#include "songstuff.hpp"
#include <vector>
#include <windows.h>
#ifndef THEACTUALBOT_HPP
#define THEACTUALBOT_HPP
namespace TheActualBot {
    class MiniBot {
        public:
            MiniBot(WORD key, std::vector<SongStuff::Note> notes);
    };
    class MiniBotsManager {
        private:
            std::vector<MiniBot> MiniBots;
        public:
            MiniBotsManager(std::vector<WORD> controls, std::vector<SongStuff::Note> notes);
    };
}
#endif