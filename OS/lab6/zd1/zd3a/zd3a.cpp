#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	HANDLE hm = OpenMutex(SYNCHRONIZE, FALSE, L"Mutex");
	if (hm == NULL)
	{
		cout << "zd3A: Open err Mutex\n";
	}
	else
	{
		cout << "zd3A: Open  Mutex\n";
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
		Sleep(100);
		cout << "zd3A: " << i << " PID: " << GetCurrentProcessId() << endl;

	}

}