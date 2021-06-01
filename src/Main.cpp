#include <iostream>
#include <windows.h>
#include "lib/hotkeymanager.hpp"
//its the main code, what a shocker
bool areWeDoneYet = false;
int nowBeDone() {
    areWeDoneYet = true;
    return 0;
}
int main() {
    TIMECAPS veryImportantTimerThing;
    timeGetDevCaps(&veryImportantTimerThing, sizeof(TIMECAPS));
    timeBeginPeriod(veryImportantTimerThing.wPeriodMin);
    std::cout << "Q: Quit" << std::endl;
    HotkeyManager::allTheCallbacks.push_back({nowBeDone, 0x51});
    while (!areWeDoneYet) {
        HotkeyManager::loopThing();
    }
    timeEndPeriod(veryImportantTimerThing.wPeriodMin);
    return 0;
}