#include "../../src/lib/keypresser.hpp"
#include <windows.h>
#include <stdio.h>
#include <thread>
int result = 0;
KeyPresser::KeyPresser * presser = nullptr;
void helper(WORD key) {
    Sleep(500);
    presser->pressKey(key);
}
void helper2(WORD key) {
    Sleep(1000);
    presser->pressKey(key);
}
DWORD WINAPI testerA(LPVOID arg) {
    std::thread helperThing(helper, 0x41);
    std::thread helperThing2(helper2, 0x0D);
    char c = getchar();
    if (c != 'a') {
        result++;
    }
    helperThing.join();
    helperThing2.join();
    return 0;
}
int main() {
    presser = new KeyPresser::KeyPresser();
    HANDLE h;
    DWORD id;
    h = CreateThread(NULL, 0, testerA, nullptr, 0, &id);
    if (h != NULL) {
        if (WaitForSingleObjectEx(h, 5000, FALSE) == WAIT_TIMEOUT) {
            result++;
        }
        CloseHandle(h);
    }
    return result;
}