#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;
int check;

//1, чтобы обозначить, что критическая секция занята, и сброшена в 0, когда она освобождаетс

void EnterCriticalSectionAssem()
{
	_asm
	{
	CriticalSection:
		lock bts check, 0;       // установить флаг в 1, если уже 1 то ждет пока освободится
		jc CriticalSection
	}
}

void LeaveCriticalSectionAssem()
{
	_asm lock btr check, 0 
}

void WINAPI loop(char* displayed_name)
{
	int pid = GetCurrentProcessId();
	int tid = GetCurrentThreadId();

	for (int i = 1; i <= 30; ++i)
	{
		if (i == 10)
			EnterCriticalSectionAssem();

		printf("%d.\tPID = %d\tTID = %u\tcheck: %d\tthread: %s\n", i, pid, tid, check, displayed_name);

		if (i == 20)
			LeaveCriticalSectionAssem();

		Sleep(100);
	}

	cout << "\n---------------" << displayed_name << " finished\n\n";
}

int main()
{
	const int size = 2;
	HANDLE threads[size];

	threads[0]  = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)loop, (char*)"A", 0, NULL);
	threads[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)loop, (char*)"B", 0, NULL);

	WaitForMultipleObjects(size, threads, TRUE, INFINITE);
	for (int i = 0; i < size; i++)
		CloseHandle(threads[i]);

	return 0;
}