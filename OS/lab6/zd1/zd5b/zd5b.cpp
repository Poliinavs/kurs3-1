﻿#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	HANDLE he = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"Event");

	if (he == NULL)
	{
		cout << "zd5B: Open error Event\n";
	}
	else
	{
		cout << "zd5B: Open Event\n";
	}

	WaitForSingleObject(he, INFINITE);
	for (int i = 1; i <= 90; i++)
	{
		SetEvent(he);

		Sleep(100);
		cout << "zd5B: " << i << " PID: " << GetCurrentProcessId() << endl;
	}
	CloseHandle(he);
	system("pause");

	return 0;
}