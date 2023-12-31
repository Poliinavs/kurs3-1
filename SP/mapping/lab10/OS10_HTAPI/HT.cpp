#include "pch.h"
#include "HT.h"

namespace HT
{
	HtHandle::HtHandle()
	{
		this->capacity = 0;
		this->secSnapshotInterval = 0;
		this->maxKeyLength = 0;
		this->maxPayloadLength = 0;
		ZeroMemory(this->fileName, sizeof(this->fileName));
		this->file = NULL;
		this->fileMapping = NULL;
		this->addr = NULL;
		ZeroMemory(this->lastErrorMessage, sizeof(this->lastErrorMessage));
		this->lastSnaptime = 0;
		this->count = 0;
	}


	HtHandle* create(
		int	  capacity,					// емкость хранилища
		int   secSnapshotInterval,		// переодичность сохранения в сек.
		int   maxKeyLength,             // максимальный размер ключа
		int   maxPayloadLength,			// максимальный размер данных
		const wchar_t* fileName)		// имя файла 
	{

		HANDLE hf = CreateFile(
			fileName,
			GENERIC_WRITE | GENERIC_READ,
			NULL,
			NULL,    //монопольный доступ к файлу
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		if (hf == INVALID_HANDLE_VALUE)
			throw "create or open file failed";

		int sizeMap = sizeof(HtHandle) + (maxKeyLength + maxPayloadLength) * capacity;
		HANDLE hm = CreateFileMapping(hf, NULL, PAGE_READWRITE, 0, sizeMap, fileName); //для создания объекта проецируемого файла, 0=отображение всего файла
		if (!hm)
			throw "create File Mapping failed";

		LPVOID lp = MapViewOfFile(hm,
			FILE_MAP_ALL_ACCESS, //полный доступ(чтение, запись)
			0, 0, //смещение в файле(с самого начала)
			0);//сколько байт в памяти(весь)
		//для отобразить нужный фрагмент файла в виртуальные адреса процесса(возвращает указатель на представление )
		if (!lp)
			return NULL;

		ZeroMemory(lp, sizeMap);

		HtHandle* htHandle = new HtHandle();
		htHandle->capacity = capacity;
		htHandle->secSnapshotInterval = secSnapshotInterval;
		htHandle->maxKeyLength = maxKeyLength;
		htHandle->maxPayloadLength = maxPayloadLength;
		memcpy(htHandle->fileName, fileName, sizeof(htHandle->fileName));
		htHandle->file = hf;
		htHandle->fileMapping = hm;
		htHandle->addr = lp;
		htHandle->lastSnaptime = time(NULL);
		htHandle->mutex = CreateMutex(NULL, FALSE, fileName); 	 //безопасность, сигнальное состояние, имя



		runSnapshotTimer(htHandle);

		return htHandle;
	}

	HtHandle* createHt(
		int	  capacity,					// емкость хранилища
		int   secSnapshotInterval,		// переодичность сохранения в сек.
		int   maxKeyLength,             // максимальный размер ключа
		int   maxPayloadLength,			// максимальный размер данных
		const wchar_t* fileName)		// имя файла 
	{
		HANDLE hf = CreateFile(
			fileName,
			GENERIC_WRITE | GENERIC_READ,
			NULL,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		if (hf == INVALID_HANDLE_VALUE)
			throw "create or open file failed";

		int sizeMap = sizeof(HtHandle) + (maxKeyLength + maxPayloadLength) * capacity;
		HANDLE hm = CreateFileMapping(
			hf,
			NULL,
			PAGE_READWRITE,
			0, sizeMap,
			fileName);
		if (!hm)
			throw "create File Mapping failed";

		LPVOID lp = MapViewOfFile(
			hm,
			FILE_MAP_ALL_ACCESS,
			0, 0, 0);
		if (!lp)
			return NULL;

		ZeroMemory(lp, sizeMap);

		HtHandle* htHandle = new HtHandle();

		htHandle->capacity = capacity;
		htHandle->secSnapshotInterval = secSnapshotInterval;
		htHandle->maxKeyLength = maxKeyLength;
		htHandle->maxPayloadLength = maxPayloadLength;
		memcpy(htHandle->fileName, fileName, sizeof(htHandle->fileName));
		htHandle->file = hf;
		htHandle->fileMapping = hm;
		htHandle->addr = lp;
		htHandle->lastSnaptime = time(NULL);
		htHandle->mutex = CreateMutex(NULL, FALSE, fileName);   //безопасность, сигнальное состояние, имя

		return htHandle;
	}

	void CALLBACK snapAsync(LPVOID prm, DWORD, DWORD)
	{
		HtHandle* htHandle = (HtHandle*)prm;
		if (snap(htHandle))
			std::cout << "-- spanshotAsync success" << std::endl;
	}

	HtHandle* open
	(
		const wchar_t* fileName)         // имя файла
	{
		HtHandle* htHandle = openHtFromFile(fileName);
		if (htHandle == NULL)
		{
			htHandle = openHtFromMapName(fileName);
			if (htHandle == NULL)
				return NULL;
		}

		runSnapshotTimer(htHandle);

		return htHandle;
	}

	HtHandle* openHtFromFile(
		const wchar_t* fileName)
	{
		HANDLE hf = CreateFile(
			fileName,
			GENERIC_WRITE | GENERIC_READ,
			NULL,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		if (hf == INVALID_HANDLE_VALUE)
			return NULL;

		HANDLE hm = CreateFileMapping(
			hf,
			NULL,
			PAGE_READWRITE,
			0, 0,
			fileName);
		if (!hm)
			return NULL;

		LPVOID lp = MapViewOfFile(
			hm,
			FILE_MAP_ALL_ACCESS,
			0, 0, 0);
		if (!lp)
			return NULL;

		HtHandle* htHandle = (HtHandle*)lp;
		htHandle->file = hf;
		htHandle->fileMapping = hm;
		htHandle->addr = lp;
		htHandle->lastSnaptime = time(NULL);

		return htHandle;
	}

	HtHandle* openHtFromMapName(
		const wchar_t* fileName)
	{
		HANDLE hm = CreateFileMapping(
			INVALID_HANDLE_VALUE,
			NULL,
			PAGE_READWRITE,
			0, sizeof(HtHandle),
			fileName);
		if (!hm)
			return NULL;

		LPVOID lp = MapViewOfFile(
			hm,
			FILE_MAP_ALL_ACCESS,
			0, 0, 0);
		if (!lp)
			return NULL;

		HtHandle* htHandle = (HtHandle*)lp;

		int sizeMapping = sizeof(HtHandle) + (htHandle->maxKeyLength + htHandle->maxPayloadLength) * htHandle->capacity;

		if (!UnmapViewOfFile(lp))
			return NULL;
		if (!CloseHandle(hm))
			return NULL;

		hm = CreateFileMapping(
			INVALID_HANDLE_VALUE,
			NULL,
			PAGE_READWRITE,
			0, sizeMapping,
			fileName);
		if (!hm)
			return NULL;

		lp = MapViewOfFile(
			hm,
			FILE_MAP_ALL_ACCESS,
			0, 0, 0);
		if (!lp)
			return NULL;

		htHandle = new HtHandle();
		memcpy(htHandle, lp, sizeof(HtHandle));
		htHandle->file = NULL;
		htHandle->fileMapping = hm;
		htHandle->addr = lp;
		htHandle->lastSnaptime = time(NULL);

		return htHandle;
	}

	BOOL runSnapshotTimer(HtHandle* htHandle)
	{
		htHandle->snapshotTimer = CreateWaitableTimer(0, FALSE, 0);    //безопасность, состояние, имя
		LARGE_INTEGER liDueTime;
		liDueTime.QuadPart = -(SECOND * htHandle->secSnapshotInterval);
		SetWaitableTimer(htHandle->snapshotTimer, &liDueTime, 1, snapAsync, htHandle, FALSE);

		return true;
	}

	Element* get     //  читать элемент из хранилища
	(
		HtHandle* htHandle,            // управление HT
		const Element* element)              // элемент 
	{
		int index = findIndex(htHandle, element);
		if (index < 0)
		{
			writeLastError(htHandle, "-- not found element (GET)");
			return NULL;
		}

		Element* foundElement = new Element();
		readFromMemory(htHandle, foundElement, index);

		return foundElement;
	}

	BOOL insert
	(
		HtHandle* htHandle,
		const Element* element)
	{
		if (htHandle->count >= htHandle->capacity)
		{
			writeLastError(htHandle, " no free memory");
			return false;
		}

		WaitForSingleObject(htHandle->mutex, INFINITE);
		int freeIndex = NextIndex(htHandle, element);
		if (freeIndex!=-1) {

			writeToMemory(htHandle, element, freeIndex);
			htHandle->count++;
			ReleaseMutex(htHandle->mutex);
			return true;
		}
		else
		{
			ReleaseMutex(htHandle->mutex);
			return false;
		}
	

		
	}

	BOOL update     //  именить элемент в хранилище
	(
		HtHandle* htHandle,            // управление HT
		const Element* oldElement,          // старый элемент (ключ, размер ключа)
		const void* newPayload,          // новые данные  
		int             newPayloadLength)     // размер новых данных
	{
		WaitForSingleObject(htHandle->mutex, INFINITE);
		int index = findIndex(htHandle, oldElement);
		if (index < 0)
		{
			writeLastError(htHandle, "-- not found element (UPDATE)");
			ReleaseMutex(htHandle->mutex);
			return false;
		}

		Element* updateElement = new Element(oldElement, newPayload, newPayloadLength);
		writeToMemory(htHandle, updateElement, index);
		ReleaseMutex(htHandle->mutex);

		return true;
	}

	BOOL remove      // удалить элемент в хранилище
	(
		HtHandle* htHandle,            // управление HT (ключ)
		const Element* element)				 // элемент 
	{
		WaitForSingleObject(htHandle->mutex, INFINITE);
		int index = findIndex(htHandle, element);
		if (index < 0)
		{
			writeLastError(htHandle, "-- not found element (DELETE)");
			ReleaseMutex(htHandle->mutex);
			return false;
		}

		clearMemoryByIndex(htHandle, index);
		--htHandle->count;
		ReleaseMutex(htHandle->mutex);

		return true;
	}

	BOOL snap         // выполнить Snapshot
	(
		HtHandle* htHandle)           // управление HT (File, FileMapping)
	{
		WaitForSingleObject(htHandle->mutex, INFINITE);
		if (!FlushViewOfFile(htHandle->addr, NULL)) { //можно принудительно записать содержимое страниц окна MMF на дисk
			writeLastError(htHandle, "-- snapshot error");
			ReleaseMutex(htHandle->mutex);
			return false;
		}
		htHandle->lastSnaptime = time(NULL);
		ReleaseMutex(htHandle->mutex);
		return true;
	}

	void print                               // распечатать элемент 
	(
		const Element* element)              // элемент 
	{
		std::cout << "Element:" << std::endl;
		std::cout << "{" << std::endl;
		std::cout << "\t\"key\": \"" << (char*)element->key << "\"," << std::endl;
		std::cout << "\t\"keyLength\": " << element->keyLength << "," << std::endl;
		std::cout << "\t\"payload\": \"" << (char*)element->payload << "\"," << std::endl;
		std::cout << "\t\"payloadLength\": " << element->payloadLength << std::endl;
		std::cout << "}" << std::endl;
	}

	BOOL close        // snap и закрыть HT  и  очистить htHandle
	(
		const HtHandle* htHandle)           // управление HT (File, FileMapping)
	{
		HANDLE hf = htHandle->file;
		HANDLE hfm = htHandle->fileMapping;

		if (!CancelWaitableTimer(htHandle->snapshotTimer))
			throw "cancel snapshotTimer failed";
		if (!UnmapViewOfFile(htHandle->addr))
			throw "unmapping view failed";
		if (!CloseHandle(hfm))
			throw "close File Mapping failed";
		if (hf != NULL)
			if (!CloseHandle(hf))
				throw "close File failed";

		return true;
	}

	int hashFunction(const char* key, int capacity)
	{
		unsigned long i = 0;
		for (int j = 0; key[j]; j++)
			i += key[j];
		return i % capacity;
	}

	int NextIndex(
		const HtHandle* htHandle,
		const Element* element)
	{
		int index = hashFunction((char*)element->key, htHandle->capacity);                  //линейное пробирование

		Element* foundElement = new Element();
		do
		{
			if (index >= htHandle->capacity)                                       //если еще есть свободные строки
			{
				index = -1;
				break;
			}

			readFromMemory(htHandle, foundElement, index);
			////////////////////////
			if (strcmp((const char*)foundElement->key, (const char*)element->key) == 0) {
				return -1;
			}

			index++;
		} while (
			foundElement->keyLength != NULL && foundElement->payloadLength != NULL);

		delete foundElement;
		return index - 1;
	}

	int findIndex(
		const HtHandle* htHandle,           // управление HT
		const Element* element)				// элемент
	{
		int index = hashFunction((char*)element->key, htHandle->capacity);

		Element* foundElement = new Element();
		do
		{
			if (index >= htHandle->capacity)
			{
				index = -1;
				break;
			}

			readFromMemory(htHandle, foundElement, index);
			index++;
		} while (
			memcmp(foundElement->key, element->key, element->keyLength) != NULL);

		delete foundElement;
		return index - 1;
	}

	BOOL writeToMemory(const HtHandle* htHandle, const Element* element, int index)
	{
		LPVOID lp = (byte*)htHandle->addr + sizeof(HtHandle) + (htHandle->maxKeyLength + htHandle->maxPayloadLength) * index;

		memcpy(lp, element->key, element->keyLength);//записываем данные ключа 
		lp = (byte*)lp + htHandle->maxKeyLength;       //переходим к следующему элементу
		memcpy(lp, &element->keyLength, sizeof(int));
		lp = (byte*)lp + sizeof(int);
		memcpy(lp, element->payload, element->payloadLength);
		lp = (byte*)lp + htHandle->maxPayloadLength;
		memcpy(lp, &element->payloadLength, sizeof(int));

		return true;
	}

	Element* readFromMemory(const HtHandle* htHandle, Element* element, int index)
	{
		LPVOID lp = (byte*)htHandle->addr + sizeof(HtHandle) + (htHandle->maxKeyLength + htHandle->maxPayloadLength) * index;

		element->key = lp;
		lp = (byte*)lp + htHandle->maxKeyLength;
		element->keyLength = *(int*)lp;                  //приведение типа+разыменовывание 
		lp = (byte*)lp + sizeof(int);
		element->payload = lp;
		lp = (byte*)lp + htHandle->maxPayloadLength;
		element->payloadLength = *(int*)lp;

		return element;
	}

	BOOL clearMemoryByIndex(const HtHandle* htHandle, int index)
	{
		LPVOID lp = (byte*)htHandle->addr + sizeof(HtHandle) + (htHandle->maxKeyLength + htHandle->maxPayloadLength) * index;
		int sizeElement = htHandle->maxKeyLength + htHandle->maxPayloadLength;

		ZeroMemory(lp, sizeElement);

		return true;
	}


	const char* writeLastError(HtHandle* const htHandle, const char* msg)
	{
		memcpy(htHandle->lastErrorMessage, msg, sizeof(htHandle->lastErrorMessage));
		return htHandle->lastErrorMessage;
	}

	const char* getLastError  // получить сообщение о последней ошибке
	(
		const HtHandle* htHandle)				// управление HT
	{
		return htHandle->lastErrorMessage;
	}
}
