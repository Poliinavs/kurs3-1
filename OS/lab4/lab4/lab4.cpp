#include <iostream>
#include <Windows.h>



using namespace std;

int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 1000; i++)
    {
        cout << i << " " << "PID: " << pid << " " << " TID: " << tid << " " << endl;
        Sleep(1000);
    }
}
//Get-Process -Name "lab4" | Select-Object -ExpandProperty Threads
//perfmon
