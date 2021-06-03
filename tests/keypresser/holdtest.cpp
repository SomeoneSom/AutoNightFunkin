#include "../../src/lib/keypresser.hpp"
#include <windows.h>
#include <chrono>
#include <iostream>
int result = 0;
KeyPresser::KeyPresser * presser = nullptr;
DWORD WINAPI testerA (LPVOID arg) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    presser->holdKey(0x41, 2000);
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - start);
    if (!((2 - time_span.count()) > -0.01 && (2 - time_span.count()) < 0.01)) {
        result++;
    }
    return 0;
}
int main() {
    presser = new KeyPresser::KeyPresser();
    TIMECAPS veryImportantTimerThing;
    timeGetDevCaps(&veryImportantTimerThing, sizeof(TIMECAPS));
    timeBeginPeriod(veryImportantTimerThing.wPeriodMin);
    HANDLE h;
    DWORD id;
    h = CreateThread(NULL, 0, testerA, nullptr, 0, &id);
    if (h != NULL) {
        if (WaitForSingleObjectEx(h, 5000, FALSE) == WAIT_TIMEOUT) {
            result++;
        }
        CloseHandle(h);
    }
    timeEndPeriod(veryImportantTimerThing.wPeriodMin);
    return result;
}