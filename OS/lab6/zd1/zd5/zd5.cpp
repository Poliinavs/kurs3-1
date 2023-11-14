#include <Windows.h>
#include <iostream>

using namespace std;


int main()
{
    PROCESS_INFORMATION pi1, pi2;
    DWORD pId = GetCurrentProcessId();
    LPCWSTR an1 = L"..\\Debug\\zd5a.exe";
    LPCWSTR an2 = L"..\\Debug\\zd5b.exe";
    HANDLE he = CreateEvent(NULL, FALSE, FALSE, L"Event");
    {
        STARTUPINFO si;
        ZeroMemory(&si, sizeof(STARTUPINFO));
        si.cb = sizeof(STARTUPINFO);

        if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1))
        {
            cout << "--Process zd5a created\n";
        }
        else
        {
            cout << "--Process zd5a not created\n";
        }
    }
    {
        STARTUPINFO si;
        ZeroMemory(&si, sizeof(STARTUPINFO));
        si.cb = sizeof(STARTUPINFO);

        if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi2))
        {
            cout << "--Process zd5b created\n";
        }
        else
        {
            cout << "--Process zd5b not created\n";
        }


        for (int i = 1; i <= 90; i++)
        {
            if (i == 25)
            {
                SetEvent(he);
            }
            cout << "PID = " << pId << ", Main Thread: " << i << endl;
            Sleep(100);

        }

        WaitForSingleObject(pi1.hProcess, INFINITE);
        WaitForSingleObject(pi2.hProcess, INFINITE);
        CloseHandle(he);
        CloseHandle(pi1.hProcess);
        CloseHandle(pi2.hProcess);

        return 0;
    }

}
