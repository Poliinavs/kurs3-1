#include <Windows.h>
#include <iostream>

using namespace std;


int main()
{
    PROCESS_INFORMATION pi1, pi2;
    DWORD pId = GetCurrentProcessId();
    LPCWSTR an1 = L"..\\Debug\\zd3a.exe";
    LPCWSTR an2 = L"..\\Debug\\zd3b.exe";
    HANDLE hm = CreateMutex(NULL, false, L"Mutex");
    {
        STARTUPINFO si;
        ZeroMemory(&si, sizeof(STARTUPINFO));
        si.cb = sizeof(STARTUPINFO);

        if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1))
        {
            cout << "--Process zd3A created\n";
        }
        else
        {
            cout << "--Process zd3A not created\n";
        }
    }
    {
        STARTUPINFO si;
        ZeroMemory(&si, sizeof(STARTUPINFO));
        si.cb = sizeof(STARTUPINFO);

        if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi2))
        {
            cout << "--Process zd3B created\n";
        }
        else
        {
            cout << "--Process zd3B not created\n";
        }


        for (int i = 1; i <= 90; i++)
        {
            if (i == 30)
            {
                WaitForSingleObject(hm, INFINITE);
            }
            if (i == 60)
            {
                ReleaseMutex(hm);
            }
            cout << "PID = " << pId << ", Main Thread: " << i << endl;
            Sleep(100);

        }

        WaitForSingleObject(pi1.hProcess, INFINITE);
        WaitForSingleObject(pi2.hProcess, INFINITE);
        CloseHandle(hm);
        CloseHandle(pi1.hProcess);
        CloseHandle(pi2.hProcess);

        return 0;
    }

}