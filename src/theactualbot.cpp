/* theactualbot:
virtually presses keys but to the json
members ending in '__' should be seen as "private"*/
#include "lib/theactualbot.hpp"
#include "lib/songstuff.hpp"
#include "lib/keypresser.hpp"
#include <vector>
#include <windows.h>
TheActualBot::MiniBotsManager::MiniBotsManager(std::vector<WORD> controls, std::vector<SongStuff::Note> notes) {
    std::vector<std::vector<SongStuff::Note>> sortedNotes;
    for (int i = 0; i < notes.size(); i++) {
        sortedNotes.at(notes.at(i).key).push_back(notes.at(i));
    }
    for (int i = 0; i < 4; i ++) {
        this->MiniBots.push_back(MiniBot(controls.at(i), sortedNotes.at(i)));
    }
}