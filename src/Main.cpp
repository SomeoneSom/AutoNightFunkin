#include <iostream>
#include <windows.h>
//its the main code, what a shocker
int main() {
    TIMECAPS veryImportantTimerThing;
    timeGetDevCaps(&veryImportantTimerThing, sizeof(TIMECAPS));
    timeBeginPeriod(veryImportantTimerThing.wPeriodMin);
    std::cout << "ok everything should be working" << std::endl;
    timeEndPeriod(veryImportantTimerThing.wPeriodMin);
    return 0;
}