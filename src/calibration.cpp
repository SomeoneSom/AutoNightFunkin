#include <iostream>
#include "lib/songstuff.hpp"
#include "lib/hotkeymanager.hpp"
#include "lib/keypresser.hpp"
#include "lib/theactualbot.hpp"
#include <chrono>
#include <vector>
#include <thread>
#include <windows.h>
std::vector<std::chrono::microseconds> theThingsIGuess;
std::chrono::steady_clock::time_point start;
std::vector<SongStuff::Note> calibrationJsonIGuess = {
    {0, 1000, 0},
    {0, 2000, 0},
    {0, 2500, 0},
    {0, 3000, 0},
    {0, 3500, 0},
    {0, 4000, 0}
};
int addToThings() {
    std::chrono::steady_clock::time_point rightNow = std::chrono::steady_clock::now();
    theThingsIGuess.push_back(std::chrono::duration_cast<std::chrono::microseconds>(rightNow - start));
    return 0;
}
int main() {
    TIMECAPS veryImportantTimerThing;
    timeGetDevCaps(&veryImportantTimerThing, sizeof(TIMECAPS));
    timeBeginPeriod(veryImportantTimerThing.wPeriodMin);
    std::cout << "Calibrating..." << std::endl;
    HotkeyManager::allTheCallbacks.push_back({addToThings, 0x87});
    TheActualBot::MiniBotsManager manager({0x87, 0x45, 0x46, 0x47}, calibrationJsonIGuess);
    manager.start();
    start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    while (!manager.checkIfTheyAreDone()) {
        HotkeyManager::loopThing();
    }
    timeEndPeriod(veryImportantTimerThing.wPeriodMin);
    double total = 0;
    for (int i = 0; i < theThingsIGuess.size(); i++) {
        total += static_cast<double>(theThingsIGuess.at(i).count()) / 1000 - calibrationJsonIGuess.at(i).time;
    }
    std::cout << "Done." << std::endl;
    std::cout << "Your offset (give or take about .2 milliseconds) should be about " << total / 6 << " milliseconds." << std::endl;
    std::cout << "Press ENTER to close this." << std::endl;
    std::cin.ignore();
    return 0;
}