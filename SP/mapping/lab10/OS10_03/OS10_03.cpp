#ifdef _WIN64
#pragma comment(lib, "../x64/debug/OS10_HTAPI.lib")
#else
#pragma comment(lib, "../debug/OS10_HTAPI.lib")
#endif

#include "../OS10_HTAPI/pch.h"
#include "../OS10_HTAPI/HT.h"

using namespace std;

int main()
{
	HT::HtHandle* ht1 = nullptr;
	HT::HtHandle* ht2 = nullptr;
//h1

	try
	{
		cout << "------- ht1 -------" << endl;
		ht1 = HT::create(1000, 3, 10, 256, L"./files/HTspace.ht");
		if (ht1)
			cout << "-- create: success" << endl;
		else
			throw "-- create: error";

		if (HT::insert(ht1, new HT::Element("key222", 7, "payload", 8)))
			cout << "-- insert: success" << endl;
		else
			throw "-- insert: error";

		HT::Element* h1 = HT::get(ht1, new HT::Element("key222", 7));
		if (h1)
			cout << "-- get: success" << endl;
		else
			throw "-- get: error";

		HT::print(h1);


	}
	catch (const char* msg)
	{
		cout << msg << endl;

		if (ht1 != nullptr)
			cout << HT::getLastError(ht1) << endl;
	}
	//ht2

	try
	{
		cout << "\n------- ht2 -------" << endl;
		ht2 = HT::open(L"./files/HTspace.ht");
		if (ht2)
			cout << "-- open: success" << endl;
		else
			throw "-- open: error";

		HT::Element* hte = HT::get(ht1, new HT::Element("key222", 7));
		if (hte)
			cout << "-- get: success" << endl;
		else
			throw "-- get: error";

		HT::print(hte);
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		if (ht1 != nullptr)
			cout << HT::getLastError(ht1) << endl;
	}


	try
	{
		if (ht1 != nullptr)
			if (HT::close(ht1))
				cout << "-- close: success (ht1)" << endl;
			else
				throw "-- close: error (ht1)";

		if (ht2 != nullptr)
			if (HT::close(ht2))
				cout << "-- close: success (ht2)" << endl;
			else
				throw "-- close: error (ht2)";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}