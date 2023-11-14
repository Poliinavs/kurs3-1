#include <iostream>
#include <thread>
#include <chrono>
#include <wtypes.h>

#define SECOND 10000000

HANDLE htimer1 = NULL;
long long it1 = -3 * SECOND;
HANDLE htimer2 = NULL;
long long it2 = -15 * SECOND;

int i = 0;

void ChildThread() {
    while (true) {
        WaitForSingleObject(htimer1, INFINITE);
        std::cout << "3 sec iterations count: " << i<<"\n";
    }
}

int main() {
    htimer1 = CreateWaitableTimer(NULL, FALSE, NULL);
    if (!SetWaitableTimer(htimer1, (LARGE_INTEGER*)&it1, 3000, NULL, NULL, FALSE))
        throw "Error SetwaitableTimer";

    HANDLE hchild = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ChildThread, NULL, NULL, NULL);

    htimer2 = CreateWaitableTimer(NULL, FALSE, NULL);
    if (!SetWaitableTimer(htimer2, (LARGE_INTEGER*)&it2, 0, NULL, NULL, FALSE))
        throw "Error SetwaitableTimer";

    while (true) {
        if (WaitForSingleObject(htimer2, 0) == WAIT_OBJECT_0) {
            Sleep(20);
            std::cout <<  "15 sec break iterations count : " << i<<"\n";
            TerminateThread(hchild, 0);
            break;
        }
        i++;
    }

   
  

    system("pause");
    return 0;
}
