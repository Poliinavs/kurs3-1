#pragma once
#ifdef _WIN64
#pragma comment(lib, "../x64/debug/OS10_HTAPI.lib")
#else
#pragma comment(lib, "../debug/OS10_HTAPI.lib")
#endif

#include "../OS10_HTAPI/pch.h"
#include "../OS10_HTAPI/HT.h"

namespace tests
{
	BOOL insertTest(HT::HtHandle* htHandle);
	BOOL removeTest(HT::HtHandle* htHandle);
	BOOL RemoveNull(HT::HtHandle* htHandle);
	BOOL getTest(HT::HtHandle* htHandle);
	BOOL getNullTest(HT::HtHandle* htHandle);
	
}
