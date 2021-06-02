/* theactualbot:
virtually presses keys but to the json
members ending in '__' should be seen as "private"*/
#include "lib/theactualbot.hpp"
#include "lib/songstuff.hpp"
#include "lib/keypresser.hpp"
#include <vector>
#include <thread>
#include <memory>
#include <chrono>
#include <windows.h>
#include <functional>
#include <math.h>
#include <iostream>
void TheActualBot::whyErrorC2280__(std::shared_ptr<MiniBot> bot) {
    bot->play();
}
TheActualBot::MiniBotsManager::MiniBotsManager(std::vector<WORD> controls, std::vector<SongStuff::Note> notes) {
    std::vector<std::vector<SongStuff::Note>> sortedNotes(4);
    for (int i = 0; i < notes.size(); i++) {
        sortedNotes.at(notes.at(i).key).push_back(notes.at(i));
    }
    for (int i = 0; i < 4; i ++) {
        miniBots.push_back(std::shared_ptr<MiniBot>(new MiniBot(controls.at(i), sortedNotes.at(i))));
    }
}
bool TheActualBot::MiniBotsManager::checkIfTheyAreDone() {
    bool result = true;
    for (int i = 0; i < miniBots.size(); i++) {
        result = result && miniBots.at(i)->shouldIStopYet;
    }
    return result;
}
int TheActualBot::MiniBotsManager::start() {
    for (int i = 0; i < miniBots.size(); i++) {
        miniBotThreads.push_back(std::shared_ptr<std::thread>(new std::thread(whyErrorC2280__, miniBots.at(i))));
        miniBotThreads.at(i)->detach();
    }
    return 0;
}
int TheActualBot::MiniBotsManager::stop() {
    for (int i = 0; i < miniBots.size(); i++) {
        miniBots.at(i)->stop();
    }
    while (!checkIfTheyAreDone()) {}
    miniBotThreads.clear();
    return 0;
}
TheActualBot::MiniBot::MiniBot(WORD key, std::vector<SongStuff::Note> notes) {
    notesVector = notes;
    keyToPress = key;
    shouldIStopYet = true;
}
int TheActualBot::MiniBot::play() {
    shouldIStopYet = false;
    int inc = 0;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point rightNow = std::chrono::steady_clock::now();
    while (!shouldIStopYet && (inc < notesVector.size())) {
        if (std::chrono::duration_cast<std::chrono::microseconds>(rightNow - start).count() / 1000 >= notesVector.at(inc).time) {
            if (notesVector.at(inc).holdTime == 0) {
                KeyPresser::pressKey(keyToPress);
            } else {
                KeyPresser::holdKey(keyToPress, static_cast<DWORD>(ceil(notesVector.at(inc).holdTime)));
            }
            inc++;
        }
        rightNow = std::chrono::steady_clock::now();
    }
    shouldIStopYet = true;
    return 0;
}
void TheActualBot::MiniBot::stop() {
    shouldIStopYet = true;
}