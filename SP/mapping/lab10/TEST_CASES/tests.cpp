#include "tests.h"

namespace tests
{

	BOOL insertTest(HT::HtHandle* htHandle)
	{
		HT::Element* element = new HT::Element("test3", 6, "test3", 6);

		HT::insert(htHandle, element);
		if (HT::insert(htHandle, element))
			return false;

		return true;
	}

	BOOL getTest(HT::HtHandle* htHandle)
	{
		HT::Element* insertEl = new HT::Element("key", 4, "hello", 6);

		HT::insert(htHandle, insertEl);
		HT::Element* getEl = HT::get(htHandle, new HT::Element("key", 4));

		if (getEl == NULL || insertEl->keyLength != getEl->keyLength || memcmp(insertEl->key, getEl->key, insertEl->keyLength) != NULL ||
			insertEl->payloadLength != getEl->payloadLength || memcmp(insertEl->payload, getEl->payload, insertEl->payloadLength) != NULL)
			return false;
		return true;
	}

	BOOL getNullTest(HT::HtHandle* htHandle)
	{
	

		HT::Element* getEl = HT::get(htHandle, new HT::Element("ky", 4));

		if (getEl != NULL)
			return false;
		return true;
	}

	BOOL removeTest(HT::HtHandle* htHandle)
	{
		HT::Element* element = new HT::Element("key1", 5, "remove", 7);

		HT::insert(htHandle, element);
		HT::remove(htHandle, element);

		if (HT::get(htHandle, element)==NULL)
			return true;

		return false;
	}
	

	BOOL RemoveNull(HT::HtHandle* htHandle)
	{
		HT::Element* element = new HT::Element("key12", 6, "remove", 7);

		HT::insert(htHandle, element);
		HT::remove(htHandle, element);
		if(HT::remove(htHandle, element))
			return false;

		return true;
	}
}