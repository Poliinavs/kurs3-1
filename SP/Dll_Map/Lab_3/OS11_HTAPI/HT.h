#pragma once
#include <Windows.h>
#include <iomanip>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

#ifdef OS11HTAPI_EXPORTS
#define OS11HTAPI __declspec(dllexport)
#else
#define OS11HTAPI __declspec(dllimport)
#endif

namespace HT    // HT API
{
	// API HT - ����������� ��������� ��� ������� � ��-��������� 
	//          ��-��������� ������������� ��� �������� ������ � �� � ������� ����/��������
	//          ���������������� (�����������) ������ �������������� � ������� snapshot-���������� 
	//          Create - �������  � ������� HT-��������� ��� �������������   
	//          Open   - ������� HT-��������� ��� �������������
	//          Insert - ������� ������� ������
	//          Delete - ������� ������� ������    
	//          Get    - ������  ������� ������
	//          Update - �������� ������� ������
	//          Snap   - �������� snapshot
	//          Close  - ��������� Snap � ������� HT-��������� ��� �������������
	//          GetLastError - �������� ��������� � ��������� ������

	extern "C" OS11HTAPI struct HTHANDLE    // ���� ���������� HT
	{
		HTHANDLE();
		HTHANDLE(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512]);
		int     Capacity;               // ������� ��������� � ���������� ��������� 
		int     SecSnapshotInterval;    // ������������� ���������� � ���. 
		int     MaxKeyLength;           // ������������ ����� �����
		int     MaxPayloadLength;       // ������������ ����� ������
		char    FileName[512];          // ��� ����� 
		HANDLE  File;                   // File HANDLE != 0, ���� ���� ������
		HANDLE  FileMapping;            // Mapping File HANDLE != 0, ���� mapping ������  
		LPVOID  Addr;                   // Addr != NULL, ���� mapview ��������  
		char    LastErrorMessage[512];  // ��������� �� ��������� ������ ��� 0x00  
		time_t  Lastsnaptime;           // ���� ���������� snap'a (time())  
		HANDLE  Mutex;
		int ElementCount; // ������� ���-�� ���������
		HANDLE SnapshotThread; //����� ��� ��������
	};

	extern "C" OS11HTAPI struct Element   // ������� 
	{
		OS11HTAPI Element();
		OS11HTAPI Element(const void* key, int keylength);                                             // for Get
		OS11HTAPI Element(const void* key, int keylength, const void* payload, int  payloadlength);    // for Insert
		OS11HTAPI Element(Element* oldelement, const void* newpayload, int  newpayloadlength);         // for update
		void* key;                 // �������� ����� 
		int             keylength;           // ������ �����
		void* payload;             // ������ 
		int             payloadlength;       // ������ ������
	};
	extern "C" OS11HTAPI HTHANDLE * OpenExist     //  ������� HT             
	(
		const wchar_t    FileName[512]         // ��� ����� 
	); 	// != NULL �������� ����������  

	extern "C" OS11HTAPI HTHANDLE * Create   //  ������� HT             
	(
		int	  Capacity,					   // ������� ��������� � ���������� ���������
		int   SecSnapshotInterval,		   // ������������� ���������� � ���.
		int   MaxKeyLength,                // ������������ ������ �����
		int   MaxPayloadLength,            // ������������ ������ ������
		const wchar_t FileName[512]          // ��� ����� 
	); 	// != NULL �������� ����������  

	extern "C" OS11HTAPI HTHANDLE * Open     //  ������� HT             
	(
		const wchar_t FileName[512]//,// ��� ����� 
		//std::string& fill
	); 	// != NULL �������� ����������  
	extern "C" OS11HTAPI HTHANDLE * OpenExist(const wchar_t FileName[512]);

	extern "C" OS11HTAPI BOOL Snap         // ��������� Snapshot
	(
		HTHANDLE * ht           // ���������� HT (File, FileMapping)
	);


	extern "C" OS11HTAPI BOOL Close        // Snap � ������� HT  �  �������� HTHANDLE
	(
		HTHANDLE * ht           // ���������� HT (File, FileMapping)
	);	//  == TRUE �������� ����������   


	extern "C" OS11HTAPI BOOL Insert      // �������� ������� � ���������
	(
		HTHANDLE * ht,            // ���������� HT
		Element * el              // �������
	);	//  == TRUE �������� ���������� 


	extern "C" OS11HTAPI BOOL Delete      // ������� ������� � ���������
	(
		HTHANDLE * ht,            // ���������� HT (����)
		Element * el              // ������� 
	);	//  == TRUE �������� ���������� 

	extern "C" OS11HTAPI Element * Get     //  ������ ������� � ���������
	(
		HTHANDLE * ht,            // ���������� HT
		Element * el              // ������� 
	); 	//  != NULL �������� ���������� 


	extern "C" OS11HTAPI BOOL Update     //  ������� ������� � ���������
	(
		HTHANDLE * ht,            // ���������� HT
		Element * oldelement,          // ������ ������� (����, ������ �����)
		const void* newpayload,          // ����� ������  
		int             newpayloadlength     // ������ ����� ������
	); 	//  != NULL �������� ���������� 

	char* GetLastError  // �������� ��������� � ��������� ������
	(
		HTHANDLE* ht                         // ���������� HT
	);

	const int DELETED = -1;

	void SetDeletedFlag(Element* el);

	void SetLastError(HTHANDLE* ht, const char* message); //

	BOOL CheckElementParm(HTHANDLE* ht, Element* el);

	BOOL CheckElementParm(HTHANDLE* ht, int payloadLength);

	BOOL CheckEqualElementKeys(Element* el1, Element* el2);

	int HashFunction(const Element* el, int size, int p);

	int NextHash(int hash, int size, int p);

	Element* GetElementFromHT(HTHANDLE* ht, int hash);

	BOOL SetElementToHT(HTHANDLE* ht, Element* el, int n);

	DWORD WINAPI SnapshotRoutine(HTHANDLE* ht);

	BOOL IsDeleted(Element* el);

	void UpdateElement(HTHANDLE* ht, Element* el, const void* newpayload, int newpayloadlength);

	extern "C" OS11HTAPI void Print                               // ����������� ������� 
	(
		const Element * el              // ������� 
	);
};
