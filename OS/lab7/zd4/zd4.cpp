#include <Windows.h>
#include <ctime>
#include <iostream>
#define SECOND 10000000
HANDLE htimer;
HANDLE htimer2;

long long i = 1;
volatile bool active = true;
using namespace std;
void main() {
    int firsttime = clock();
    DWORD pid = GetCurrentProcessId();
    cout << "pid: " << pid << endl;

    htimer = CreateWaitableTimer(NULL, FALSE, L"atimer1");
    htimer2 = CreateWaitableTimer(NULL, FALSE, L"atimer2");

    long long time1 = -5 * SECOND;
    long long time2 = -10 * SECOND;

    if (!SetWaitableTimer(htimer, (LARGE_INTEGER*)&time1, 0, NULL, NULL, FALSE)) throw "Err SetWaitableTimer1";
    if (!SetWaitableTimer(htimer2, (LARGE_INTEGER*)&time2, 0, NULL, NULL, FALSE)) throw "Err SetWaitableTimer2";

    std::cout << "Start timers" << std::endl;

    LPCWSTR an = L"C:\\kurs3_1\\OS\\lab7\\Debug\\zd4_1.exe";
    STARTUPINFO si1;
    STARTUPINFO si2;
    PROCESS_INFORMATION pi1;
    PROCESS_INFORMATION pi2;

    ZeroMemory(&si1, sizeof(STARTUPINFO));
    ZeroMemory(&si2, sizeof(STARTUPINFO));

    si1.cb = sizeof(STARTUPINFO);
    si2.cb = sizeof(STARTUPINFO);

    wchar_t cLine1[] = L"C:\kurs3_1\OS\lab7\Debug\\zd4_1.exe 1";
    wchar_t cLine2[] = L"C:\kurs3_1\OS\lab7\Debug\\zd4_1.exe 2";

    if (CreateProcess(an, cLine1, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
        cout << "Child Process created" << endl;
    else
        cout << "Child Process not created" << endl;

    if (CreateProcessW(an, cLine2, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2))
        cout << "Child Process created" << endl;
    else
        cout << "Child Process not created" << endl;

    WaitForSingleObject(pi1.hProcess, 1000);
    WaitForSingleObject(pi2.hProcess, 1000);

    // Добавьте следующий код после ожидания обоих процессов:
    CloseHandle(pi1.hProcess);
    CloseHandle(pi2.hProcess);

    // Завершить основной процесс
    ExitProcess(0);
    CancelWaitableTimer(htimer);
    CancelWaitableTimer(htimer2);

    cout << "time:" << clock() - firsttime;
    system("pause");
}