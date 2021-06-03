#include <iostream>
#include <windows.h>
#include "lib/songstuff.hpp"
#include "lib/hotkeymanager.hpp"
#include "lib/keypresser.hpp"
#include "lib/theactualbot.hpp"
#include <chrono>
#include <string>
#include <sstream>
//its the main code, what a shocker
double offset = 0;
std::string filename = "";
bool started = false;
bool areWeDoneYet = false;
TheActualBot::MiniBotsManager * manager = nullptr;
int nowBeDone() {
    areWeDoneYet = true;
    return 0;
}
void displayOptions() {
    std::cout << "F1: Enter Song Path (" << filename << ")" << std::endl;
    std::cout << "F2: Offset + 0.1 (" << offset << " ms)" << std::endl;
    std::cout << "F3: Offset - 0.1 (" << offset << " ms)" << std::endl;
    std::cout << "F4: Start/Stop" << std::endl;
    std::cout << "Q: Quit" << std::endl;
}
int offsetUp() {
    if (!started) {
        offset += 0.1;
        if (offset == 2.77556e-17) {
            offset = 0;
        }
        displayOptions();
    }
    return 0;
}
int offsetDown() {
    if (!started) {
        offset -= 0.1;
        if (offset == 2.77556e-17) {
            offset = 0;
        }
        displayOptions();
    }
    return 0;
}
int setFile() {
    return 0;
}
int main() {
    TIMECAPS veryImportantTimerThing;
    timeGetDevCaps(&veryImportantTimerThing, sizeof(TIMECAPS));
    timeBeginPeriod(veryImportantTimerThing.wPeriodMin);
    displayOptions();
    HotkeyManager::allTheCallbacks.push_back({setFile, 0x70});
    HotkeyManager::allTheCallbacks.push_back({offsetUp, 0x71});
    HotkeyManager::allTheCallbacks.push_back({offsetDown, 0x72});
    HotkeyManager::allTheCallbacks.push_back({nowBeDone, 0x51});
    while (!areWeDoneYet) {
        HotkeyManager::loopThing();
    }
    timeEndPeriod(veryImportantTimerThing.wPeriodMin);
    return 0;
}