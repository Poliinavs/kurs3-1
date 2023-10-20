
#include <iostream>

#include <Windows.h>

//zd3.exe 255 2 3 3
//zd3.exe 255 2 1 5
//zd3.exe 1 2 1 5

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
    cout << "Идентификатор текущего процесса: " << currentProcessId << endl;

    DWORD currentThreadId = GetCurrentThreadId();
    cout << "Идентификатор текущего потока: " << currentThreadId << endl;

    DWORD processPriority = GetPriorityClass(GetCurrentProcess());
    cout << "Приоритет текущего процесса: " << processPriority << endl;
    ProcessPreor(processPriority);

    DWORD threadPriority = GetThreadPriority(GetCurrentThread());
    cout << "Приоритет текущего потока: " << threadPriority << endl;
    ThreadPreor(threadPriority);

    int currentThreadProcessor = GetCurrentProcessorNumber();
    cout << "Процессор, назначенный текущему потоку: " << currentThreadProcessor << endl;

}


DWORD WINAPI printCycle1()
{
    setlocale(LC_ALL, "russian");
    HANDLE ph = GetCurrentProcess();
    HANDLE th = GetCurrentThread();
      cout << "\n\n";
    for (int i = 0; i < 1000000; i++)
    {
        if (i % 1000 == 0)
        {
            inform(i);

            Sleep(200);
        }
    }
    return 0;
}

DWORD WINAPI printCycle2()
{
    HANDLE ph = GetCurrentProcess();
    HANDLE th = GetCurrentThread();
      cout << "\n\n";
    for (int i = 0; i < 1000000; i++)
    {
        if (i % 1000 == 0)
        {
            inform(i);

            Sleep(200);
        }
    }
    return 0;
}



void SetProcPrior(HANDLE hp, int priority)
{
    if (priority == 1)
    {
        SetPriorityClass(hp, IDLE_PRIORITY_CLASS);
    }
    if (priority == 2)
    {
        SetPriorityClass(hp, NORMAL_PRIORITY_CLASS);
    }
    if (priority == 3)
    {
        SetPriorityClass(hp, HIGH_PRIORITY_CLASS);
    }
    if (priority == 4)
    {
        SetPriorityClass(hp, REALTIME_PRIORITY_CLASS);
    }
}





DWORD SetPriorTr(int i)
{
    switch (i)
    {
    case 1: return THREAD_PRIORITY_LOWEST;
    case 2: return THREAD_PRIORITY_BELOW_NORMAL;
    case 3: return THREAD_PRIORITY_NORMAL;
    case 4: return THREAD_PRIORITY_ABOVE_NORMAL;
    case 5: return THREAD_PRIORITY_HIGHEST;
    case 6: return THREAD_PRIORITY_IDLE;
    default: throw "No such priority class";
    }
}


int main(int argc, char* argv[])
{
    if (argc == 5) {
        for (int i = 0; i < argc; i++)
        {
            cout << "arg" << i << ": " << argv[i] << "\n";
        }
        HANDLE hProcess = GetCurrentProcess();                                                                                                    // Получаем дескриптор текущего процесса
        // Новая маска доступности (например, биты 0 и 1 установлены)
        int mask = atoi(argv[1]);
        if (SetProcessAffinityMask(hProcess, mask)) {
            DWORD_PTR processAffinityMask, systemAffinityMask;
            GetProcessAffinityMask(GetCurrentProcess(), &processAffinityMask, &systemAffinityMask);
            cout << "New Mask. Value:" << processAffinityMask << endl;

            //2
            SetProcPrior(GetCurrentProcess(), atoi(argv[2]));

            //3
         

            DWORD FirstId = NULL;
            HANDLE FirstTr = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)printCycle1, NULL, CREATE_SUSPENDED, &FirstId);

            SetThreadPriority(FirstTr, SetPriorTr(atoi(argv[3])));
            ResumeThread(FirstTr);
            //
            DWORD SecondId = NULL;
            HANDLE SecondTr = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)printCycle2, NULL, CREATE_SUSPENDED, &SecondId);
            SetThreadPriority(SecondTr, SetPriorTr(atoi(argv[4])));


            ResumeThread(SecondTr);




        }
        else {
            DWORD error = GetLastError();
            cerr << "Ошибка при установке новой маски доступности, код ошибки: " << error << endl;
        }



    }
    else {
        cout << "Error";
    }




 
   

    system("pause");
}