
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HT.h"
#include "Element.h"
#include <string>
#include <Windows.h>
#pragma comment(lib, "OS11_HTAPI")

using namespace std;

bool checkInt(char* input);
//arguments: file (location + name), sizeFile, snapTime, maxKeyLenght, maxPayloadLenght

int main(int argc, char* argv[])	// OS11_CREATE.exe ../../Files/newHT.ht 1000 5 20 10
{
	//HINSTANCE load = LoadLibrary(L"../debug/OS11_HTAPI"); //����� �����������
	setlocale(LC_ALL, "Ru");

	try
	{
		if (argc != 6)
		{
			throw "������� ���������� ����������: 6";
		}
		if (!checkInt(argv[2]) || !checkInt(argv[3]) || !checkInt(argv[4]) || !checkInt(argv[5]))
		{
			throw "������� ���������� ��������";
		}
		const size_t cSize = strlen(argv[1]) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, argv[1], cSize);


		if (GetFileAttributes(wc) != INVALID_FILE_ATTRIBUTES)
		{
			throw "���� ��� ����������";
		}

		int capacity = stoi(argv[2]);
		int snapshotinterval = stoi(argv[3]);
		int maxKeyLength = stoi(argv[4]);
		int maxPayloadLength = stoi(argv[5]);

		HT::HTHANDLE* HT = HT::Create(capacity, snapshotinterval, maxKeyLength, maxPayloadLength, wc);
		if (HT == NULL)
		{
			throw "��������� �� �������";
		}

		cout << "HT-Storage Created!" << endl;
		wcout << "filename = " << wc << endl;
		cout << "snapshotinterval = " << snapshotinterval << endl;
		cout << "capacity = " << capacity << endl;
		cout << "maxkeylength = " << maxKeyLength << endl;
		cout << "maxdatalength = " << maxPayloadLength << endl;

		HT::Close(HT);
	}
	catch (const char* err)
	{
		cout << err << endl;
		exit(-1);
	}

	exit(0);
}

bool checkInt(char* input)
{
	int i = 0;
	while (input[i] != '\0')
	{
		if (input[i] < '0' || input[i] > '9')
			return false;
		i++;
	}
	return true;
}