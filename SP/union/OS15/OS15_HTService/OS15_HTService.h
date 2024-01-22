#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <string>
#include "sddl.h"

#include "../OS15_HTCOM_LIB/pch.h"
#include "../OS15_HTCOM_LIB/OS15_HTCOM_LIB.h"

#define SERVICENAME L"OS15_HTService"
#define HTPATH L"Y:/OS15/htSpace.ht"

#define USERNAME L"UserAp1"
#define PASSWORD L"1"

#define TRACEPATH L"Y:/OS15/x64/Debug/os_15.trace"

VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
VOID WINAPI ServiceHandler(DWORD fdwControl);

SECURITY_ATTRIBUTES getSecurityAttributes();
HANDLE createStopEvent(const wchar_t* stopEventName);
void startService();
void trace(const char* msg, int r = std::ofstream::app);
