#include "tests.h"

using namespace std;

int main()
{
	HT::HtHandle* ht = HT::create(1000, 3, 10, 256, L"./files/HTspace.ht");
	if (ht)
		cout << "-- create: success" << endl;
	else
		throw "-- create: error";

	if (tests::insertTest(ht))
		cout << "-- insertTest: success" << endl;
	else
		cout << "-- insertTest: error" << endl;

	if (tests::removeTest(ht))
		cout << "-- removeTest: success" << endl;
	else
		cout << "-- removeTest: error" << endl;

	if (tests::getTest(ht))
		cout << "-- getTest: success" << endl;
	else
		cout << "-- getTest: error" << endl;

	if (tests::getNullTest(ht))
		cout << "-- getNullTest: success" << endl;
	else
		cout << "-- getNullTest: error" << endl;

	if (tests::RemoveNull(ht))
		cout << "-- RemoveNull: success" << endl;
	else
		cout << "-- RemoveNull: error" << endl;

	if (ht != nullptr)
		if (HT::close(ht))
			cout << "-- close: success" << endl;
		else
			throw "-- close: error";
}