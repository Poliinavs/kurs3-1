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
	HT::HtHandle* ht = nullptr;
	try
	{
		ht = HT::create(1000, 1, 10, 256, L"./files/HTspace.ht");
		if (ht)
			cout << "-- create: success" << endl;
		else
			throw "-- create: error";

		if (HT::insert(ht, new HT::Element("key222", 6, "payload", 8)))
			cout << "-- insert: success" << endl;
		else
			throw "-- insert: error";

		HT::Element* hte = HT::get(ht, new HT::Element("key222", 6));
		if (hte)
			cout << "-- get: success" << endl;
		else
			throw "-- get: error";

		HT::print(hte);

		if (HT::update(ht, hte, "newPayload", 11))
			cout << "-- update: success" << endl;
		else
			throw "-- update: error";

		if (HT::snap(ht))
			cout << "-- snapSync: success" << endl;
		else
			throw "-- snap: error";

		hte = HT::get(ht, new HT::Element("key222", 6));
		if (hte)
			cout << "-- get: success" << endl;
		else
			throw "-- get: error";

		HT::print(hte);

		SleepEx(1000, TRUE);

		if (HT::remove(ht, hte))
			cout << "-- remove: success" << endl;
		else
			throw "-- remove: error";

		hte = HT::get(ht, new HT::Element("key2", 4));
		if (hte)
			cout << "-- get: success" << endl;
		else
			throw "-- get: error";
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		if (ht != nullptr)
			cout << HT::getLastError(ht) << endl;
	}

	try
	{
		if (ht != nullptr)
			if (HT::close(ht))
				cout << "-- close: success" << endl;
			else
				throw "-- close: error";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}