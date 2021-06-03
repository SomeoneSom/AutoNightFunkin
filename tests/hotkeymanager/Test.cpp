#include "../../src/lib/hotkeymanager.hpp"
#include "../../src/lib/keypresser.hpp"
#include <windows.h>
#include <vector>
#include <thread>
#include <chrono>
int result = 0;
KeyPresser::KeyPresser * presser = nullptr;
void helper(WORD key) {
    Sleep(500);
    presser->pressKey(key);
}
int ifItWorks() {
    result--;
    return 0;
}
int main() {
    presser = new KeyPresser::KeyPresser();
    HotkeyManager::allTheCallbacks.push_back({ifItWorks, 0x41});
    std::thread helperThing(helper, 0x41);
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - start).count() < 2) {
        HotkeyManager::loopThing();
    }
    result++;
    helperThing.detach();
    return result;
}