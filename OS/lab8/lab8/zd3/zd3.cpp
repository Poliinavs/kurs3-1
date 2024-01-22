// zd3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <Windows.h>
#include <iostream>
using namespace std;

void sh(HANDLE pheap)
{
    PROCESS_HEAP_ENTRY phe;
    phe.lpData = NULL;
    DWORD size = 0;
    while (HeapWalk(pheap, &phe))
    {
        size += phe.cbData;
        if (phe.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE)
        {
            cout << "-- address = " << hex << phe.lpData
                << ", size = " << dec << phe.cbData << " U" << "\n";;// нераспределенная область
        }
        else if (phe.wFlags & PROCESS_HEAP_ENTRY_BUSY)
        {
            cout << "-- address = " << hex << phe.lpData
                << ", size = " << dec << phe.cbData << " B" << "\n";;// распределенная область
        }

    }
    std::cout << "size of the heap: " << size << endl;
    std::cout << "-----------------------------------\n\n";
}

int main()
{
    HANDLE pheap = GetProcessHeap();

    sh(pheap);
    {
        int size = 300000;
        int* m = new int[size];
        cout << "-- m = " << hex << m << " \n\n";
    }
    sh(pheap);
    system("pause");
}
