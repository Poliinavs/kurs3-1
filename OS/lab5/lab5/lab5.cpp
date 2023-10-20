#include <iostream>
#include <windows.h>
#include <bitset>
using namespace std;
int CountSetBits(DWORD_PTR bitMask) {
    int count = 0;
    while (bitMask) {
        count += bitMask & 1;
        bitMask >>= 1;
    }
    return count;
}


void ThreadPreor(DWORD prty)
{
  

    switch (prty)
    {
    case THREAD_PRIORITY_LOWEST:  cout << "  Priority = THREAD_PRIORITY_LOWEST \n"; break;
    case THREAD_PRIORITY_BELOW_NORMAL:  cout << "Приоритет потока = THREAD_PRIORITY_BELOW_NORMAL \n"; break;
    case THREAD_PRIORITY_NORMAL:  cout << "Приоритет потока = THREAD_PRIORITY_NORMAL \n"; break;
    case THREAD_PRIORITY_ABOVE_NORMAL:  cout << "Приоритет потока = THREAD_PRIORITY_ABOVE_NORMAL \n"; break;
    case THREAD_PRIORITY_HIGHEST:  cout << "Приоритет потока = THREAD_PRIORITY_HIGHEST \n"; break;
    case THREAD_PRIORITY_IDLE:  cout << "Приоритет потока = THREAD_PRIORITY_IDLE \n"; break;
    case THREAD_PRIORITY_TIME_CRITICAL:  cout << "Приоритет потока = THREAD_PRIORITY_TIME_CRITICAL \n"; break;
    default:  cout << "No such preoerity \n"; break;
    }

    return;
}
void ProcessPreor(DWORD prty)
{

    switch (prty)
    {
    case IDLE_PRIORITY_CLASS:  cout << "Приоритет процесса  = IDLE_PRIORITY_CLASS \n"; break;
    case BELOW_NORMAL_PRIORITY_CLASS:  cout << "Приоритет процесса  = BELOW_NORMAL_PRIORITY_CLASS \n"; break;
    case NORMAL_PRIORITY_CLASS:  cout << "Приоритет процесса  = NORMAL_PRIORITY_CLASS \n"; break;
    case ABOVE_NORMAL_PRIORITY_CLASS:  cout << "Приоритет процесса  = ABOVE_NORMAL_PRIORITY_CLASS \n"; break;
    case HIGH_PRIORITY_CLASS:  cout << "Приоритет процесса  = HIGH_PRIORITY_CLASS \n"; break;
    case REALTIME_PRIORITY_CLASS:  cout << "Приоритет процесса  = REALTIME_PRIORITY_CLASS \n"; break;
    default:  cout << "No such preoerity \n"; break;
    }
    return;
}


int main() {
    SetConsoleOutputCP(1251);

    DWORD currentProcessId = GetCurrentProcessId();
     cout << "Идентификатор текущего процесса: " << currentProcessId <<  endl;

    DWORD currentThreadId = GetCurrentThreadId();
     cout << "Идентификатор текущего (main) потока: " << currentThreadId <<  endl;

    DWORD processPriority = GetPriorityClass(GetCurrentProcess());
     cout << "Приоритет текущего процесса: " << processPriority <<  endl;
    ProcessPreor(processPriority);

    DWORD threadPriority = GetThreadPriority(GetCurrentThread());
     cout << "Приоритет текущего потока: " << threadPriority <<  endl;
    ThreadPreor(threadPriority);

    DWORD_PTR processAffinityMask, systemAffinityMask;
    GetProcessAffinityMask(GetCurrentProcess(), &processAffinityMask, &systemAffinityMask); // Получим маску доступных процессоров для текущего процесса и системы
     bitset<32> binaryNumber(processAffinityMask);                                                                    // 32 - это количество битов, подходящее для int
     cout << "Маска доступных процессоров в двоичном виде: " << binaryNumber <<  endl;
   
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    int numberOfProcessors = sysInfo.dwNumberOfProcessors;
     cout << "Количество процессоров доступных процессу: " << numberOfProcessors <<  endl;

    int currentThreadProcessor = GetCurrentProcessorNumber();
     cout << "Процессор, назначенный текущему потоку: " << currentThreadProcessor <<  endl;

    return 0;
}
