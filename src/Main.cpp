/* main:
this is what runs everything
version 1.0.0 */
#include <iostream>
#include <windows.h>
#include "lib/songstuff.hpp"
#include "lib/hotkeymanager.hpp"
#include "lib/keypresser.hpp"
#include "lib/theactualbot.hpp"
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>
double offset = 0;
std::string filename = "temp.temp";
bool started = false;
bool anotherFlag = false;
bool areWeDoneYet = false;
std::vector<std::vector<WORD>> controls = {{0x44, 0x46, 0x4a, 0x4b}, {0x41, 0x53, 0x57, 0x44}, {0x25, 0x28, 0x26, 0x27}};
std::vector<std::string> controlStrings = {"DFJK", "WASD", "Arrow Keys"};
int controlIndex = 0;
TheActualBot::MiniBotsManager * manager = nullptr;
int nowBeDone() {
    areWeDoneYet = true;
    return 0;
}
void displayOptions() {
    std::cout << "F1: Enter Song Path (" << filename << ")" << std::endl;
    std::cout << "F2: Offset + 0.1 (" << offset << " ms)" << std::endl;
    std::cout << "F3: Offset - 0.1 (" << offset << " ms)" << std::endl;
    std::cout << "F4: Change Control Scheme (" << controlStrings.at(controlIndex) << ")" << std::endl;
    std::cout << "F5: Start/Stop" << std::endl;
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
int changeControls() {
    if (!started) {
        controlIndex++;
        if (controlIndex == 3) {
            controlIndex = 0;
        }
        displayOptions();
    }
    return 0;
}
int setFile() {
    if (!started) {
        std::cout << "Enter path to JSON file (dont make this blank or it will crash): ";
        std::getline(std::cin, filename);
        displayOptions();
    }
    return 0;
}
int startStop() {
    if (!started) {
        if (filename.substr(filename.size() - 5) != ".json" || !std::filesystem::exists(std::filesystem::path(filename))) {
            std::cout << "File was either not found or is not a JSON file." << std::endl;
            displayOptions();
            return 0;
        }
        anotherFlag = false;
        started = true;
        manager = new TheActualBot::MiniBotsManager(controls.at(controlIndex), SongStuff::loadSongFromJSON(filename));
        std::cout << "Started" << std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(offset * 1000)));
        manager->start();
        Sleep(5);
    } else {
        anotherFlag = true;
        started = false;
        manager->stop();
        delete manager;
        std::cout << "Stopped" << std::endl;
        displayOptions();
    }
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
    HotkeyManager::allTheCallbacks.push_back({changeControls, 0x73});
    HotkeyManager::allTheCallbacks.push_back({startStop, 0x74});
    HotkeyManager::allTheCallbacks.push_back({nowBeDone, 0x51});
    while (!areWeDoneYet) {
        if (started) {
            if (!anotherFlag && manager->checkIfTheyAreDone()) {
                startStop();
            }
        }
        HotkeyManager::loopThing();
    }
    timeEndPeriod(veryImportantTimerThing.wPeriodMin);
    return 0;
}