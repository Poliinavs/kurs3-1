#include <Windows.h>
#include <iostream>

DWORD pid = NULL;
using namespace std;

DWORD WINAPI FirstThread() {
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 50; i++)
	{
		cout << i << ". FirstThread: " << "PID: " << pid << " " << "TID: " << tid << ";" << endl;


		Sleep(1000);
	}

	return 0;
}

DWORD WINAPI SecondThread() {
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 125; i++)
	{
		cout << i << ". SecondThread: " << "PID: " << pid << " " << "TID: " << tid << ";" << endl;

		Sleep(1000);

	}

	return 0;
}



int main()
{
	pid = GetCurrentProcessId();

	DWORD tid = GetCurrentThreadId();
	DWORD firstId = NULL;
	DWORD SecondId = NULL;
	HANDLE firstTr = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)FirstThread, NULL, 0, &firstId);
	HANDLE SecondTr = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SecondThread, NULL, 0, &SecondId);

	for (int i = 0; i < 100; i++)
	{
		cout << i << " " << "main thread: " << "PID: " << pid << " " << "TID: " << tid << "." << endl;
		if (i == 5) {
			cout << "\n Terminate SecondTr \n";
			TerminateThread(SecondTr, -1);
		}
		Sleep(1000);

	}




	WaitForSingleObject(firstTr, INFINITE);
	CloseHandle(firstTr);


}