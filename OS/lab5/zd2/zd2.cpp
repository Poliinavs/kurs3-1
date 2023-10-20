#include <iostream>
#include <windows.h>
using namespace std;

void ThreadPreor(DWORD prty)
{


    switch (prty)
    {
    case THREAD_PRIORITY_LOWEST:  cout << "Приоритет потока = THREAD_PRIORITY_LOWEST \n"; break;
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


void inform(int i) {
    cout << "Номер итерации: " << i << endl;

    DWORD currentProcessId = GetCurrentProcessId();
     cout << "Идентификатор текущего процесса: " << currentProcessId <<  endl;

    DWORD currentThreadId = GetCurrentThreadId();
     cout << "Идентификатор текущего потока: " << currentThreadId <<  endl;

    DWORD processPriority = GetPriorityClass(GetCurrentProcess());
     cout << "Приоритет текущего процесса: " << processPriority <<  endl;
    ProcessPreor(processPriority);

    DWORD threadPriority = GetThreadPriority(GetCurrentThread());
     cout << "Приоритет текущего потока: " << threadPriority <<  endl;
    ThreadPreor(threadPriority);

    int currentThreadProcessor = GetCurrentProcessorNumber();
     cout << "Процессор, назначенный текущему потоку: " << currentThreadProcessor <<  endl;

}

int main() {
    SetConsoleOutputCP(1251);


   /* for (int i = 0; i < 1000000; ++i) {*/
    for (int i = 0; i < 4000; ++i) {
        if (i % 1000== 0 ) {
            inform(i);
            
        }
        Sleep(200);
    }

    return 0;
}