#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{

	HANDLE hs = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, L"Sem");
	if (hs == NULL)
	{
		cout << "zd04A: Open error Semaphore\n";
	}
	else
	{
		cout << "zd04A: Open Semaphore\n";
	}

	LONG prevcount = 0;
	for (int i = 1; i <= 90; i++)
	{
		if (i == 30)
		{
			WaitForSingleObject(hs, INFINITE);
		}
		if (i == 60)
		{
			ReleaseSemaphore(hs, 1, &prevcount);
			cout << "zd04A: prevcount = " << prevcount << endl;
		}
		Sleep(100);
		cout << "zd04A: " << i << " PID: " << GetCurrentProcessId() << endl;
	}

	CloseHandle(hs);
	system("pause");

	return 0;
}