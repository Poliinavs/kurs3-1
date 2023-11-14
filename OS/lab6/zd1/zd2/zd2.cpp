#include <iostream>
#include <windows.h>
using namespace std;
CRITICAL_SECTION critical_section;


void WINAPI loop(char* displayed_name)
{
	int pid = GetCurrentProcessId();
	int tid = GetCurrentThreadId();

	for (int i = 1; i <= 50; ++i)
	{
		if (i == 10) {
			EnterCriticalSection(&critical_section);
		}
			


		printf("  %s\t    %d.   PID = %d\tTID = %u\n", displayed_name, i, pid, tid);

		if (i == 30)
			LeaveCriticalSection(&critical_section); {
		}

		Sleep(100);
				if (i == 30)
		{
			EnterCriticalSection(&critical_section);
			LeaveCriticalSection(&critical_section);
		}
	}

	cout << "\n------------  " << displayed_name << " finished \n\n";
}

int main()
{
	int pid = GetCurrentProcessId();

	HANDLE threads[2];

	threads[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)loop, (char*)"A", 0, NULL);
	threads[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)loop, (char*)"B", 0, NULL);

	InitializeCriticalSection(&critical_section);

	for (int i = 1; i <= 50; ++i)
	{
		if (i == 10)
			EnterCriticalSection(&critical_section);

		printf("main\t    %d.   PID = %d\n", i, pid);

		if (i == 30)
			LeaveCriticalSection(&critical_section);

		Sleep(100);
		if (i == 30)
		{
			EnterCriticalSection(&critical_section);
			LeaveCriticalSection(&critical_section);
		}
	}

	cout << "\n--------------------  MAIN finished\n\n";
	WaitForMultipleObjects(2, threads, TRUE, INFINITE);
	for (int i = 0; i < 2; ++i)
		CloseHandle(threads[i]);

	DeleteCriticalSection(&critical_section);
	return 0;
}
