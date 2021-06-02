/* theactualbot:
virtually presses keys but to the json
members ending in '__' should be seen as "private"*/
#include "keypresser.hpp"
#include "songstuff.hpp"
#include <vector>
#include <thread>
#include <memory>
#include <windows.h>
#ifndef THEACTUALBOT_HPP
#define THEACTUALBOT_HPP
namespace TheActualBot {
    class MiniBot {
        private:
            WORD keyToPress;
        public:
            bool shouldIStopYet;
            std::vector<SongStuff::Note> notesVector;
            MiniBot(WORD key, std::vector<SongStuff::Note> notes);
            int play();
            void stop();
    };
    class MiniBotsManager {
        private:
            std::vector<std::shared_ptr<std::thread>> miniBotThreads;
        public:
            MiniBotsManager(std::vector<WORD> controls, std::vector<SongStuff::Note> notes);
            std::vector<std::shared_ptr<MiniBot>> miniBots;
            bool checkIfTheyAreDone();
            int start();
            int stop();
    };
    void whyErrorC2280__(std::shared_ptr<MiniBot> bot);
}
#endif