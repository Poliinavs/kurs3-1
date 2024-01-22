// zd2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

//
#include <Windows.h>
#include <locale>
#include <iostream>
using namespace std;
#define KB (1024)
#define MB (1024 * KB)
#define PG (4 * KB)
//


//	// А=0xC0=192
//	// В=0xC2=194
//	// С=0xC1=193
//192 * 4096 = 786432(10) = 0xC0000  - добавить для перехода на страницу
//	// 
//	//смещение  C2C=0x00000C2C 
//	//искомое смещение= начало массива+0x00000C2C +0xC0

//
//int main()
//{
//    setlocale(LC_ALL, "ru");
//    int pages = 256;
//    int countItems = pages * PG / sizeof(int);
//    SYSTEM_INFO system_info;
//    GetSystemInfo(&system_info);
//
// 
//
//    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);   // выделено 1024 KB виртуальной памяти
//    cout << "\tВыделено " << pages * PG / 1024 << " KB вирт. памяти\n";
//
//    int* arr = (int*)xmemaddr;
//    for (int i = 0; i < countItems; i++)
//        arr[i] = i;
//
//    int* byte = arr + 192 * 1024 + 0x00000C2C;
//    cout << "------  Значение памяти в байте: " << *byte << "  ------\n";
//
//}

 int main() {
	    const int pageSize = 4096; // Размер страницы в байтах
	    const int numPages = 256;   // Количество страниц
	
	    // Выделение памяти для 256 страниц
	    char* memory = new char[pageSize * numPages];
	
	    // Размещение массива int, занимающего все 256 страниц
	    int* intArray = reinterpret_cast<int*>(memory);
	
	    // Заполнение массива нарастающей последовательностью
	    for (int i = 0; i < pageSize * numPages / sizeof(int); ++i) {
	        intArray[i] = i + 1;
	    }
	
	    // Запись 3 первых букв фамилии в 16-ричном представлении
	    const char lastName[] = { 0xC0, 0xC2, 0xC1 };
	    // Копирование букв в память (выберите страницу и смещение внутри страницы)
	    memcpy(memory, lastName, sizeof(lastName));
	
	    // Отображение успешного завершения
	    std::cout << "OS06_03: Completed successfully." << std::endl;
	
	    // Освобождение памяти
	    delete[] memory;
	
	    return 0;
	}