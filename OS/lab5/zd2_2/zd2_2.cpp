// zd2_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//zd2_2.exe 255 2 2
//zd2_2.exe 255 1 3
//zd2_2.exe 1 1 3


#include <iostream>
#include <wtypes.h>
using namespace std;

void CreateProcces(LPCWSTR pass,  int priority)
{

    PROCESS_INFORMATION pi;

    STARTUPINFO si;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
   
    if (priority == 1)
    {
        if (CreateProcess(pass, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | BELOW_NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi))
             cout << "-- Process zd2 created\n";
        else   cout << "-- Process zd2 not created\n";
    }
    else if (priority == 2)
    {
        if (CreateProcess(pass, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi))
             cout << "-- Process zd2 created\n";
        else   cout << "-- Process zd2 not created\n";
    }
    else if (priority == 3)
    {
        if (CreateProcess(pass, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | HIGH_PRIORITY_CLASS, NULL, NULL, &si, &pi))
             cout << "-- Process zd2 created\n";
        else   cout << "-- Process zd2 not created\n";
    }
    else if (priority == 4)
    {
        if (CreateProcess(pass, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | REALTIME_PRIORITY_CLASS, NULL, NULL, &si, &pi))
             cout << "-- Process zd2 created\n";
        else   cout << "-- Process zd2 not created\n";
    }
    else {
        cout << "Введите корректное значение приоритета"<<endl;
    }

}




int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "russian");
    if (argc == 4) {
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
             cout << "Новая маска доступности установлена успешно. Значение:" << processAffinityMask <<  endl;


            CreateProcces(L"zd2.exe", atoi(argv[2]));
            CreateProcces(L"zd2.exe", atoi(argv[3]));



        }
        else {
            DWORD error = GetLastError();
             cerr << "Ошибка при установке новой маски доступности, код ошибки: " << error <<  endl;
        }



    }
    else {
        cout << "Error";
    }
  
}

