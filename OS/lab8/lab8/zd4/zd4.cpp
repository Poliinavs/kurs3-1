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
                << ", size = " << dec << phe.cbData << " U" << "\n"; // нераспределенная область
        }
        else if (phe.wFlags & PROCESS_HEAP_ENTRY_BUSY)
        {
            cout << "-- address = " << hex << phe.lpData
                << ", size = " << dec << phe.cbData << " B" << "\n"; // распределенная область
        }
    }
    std::cout << "size of the heap: " << size << endl;
    std::cout << "-----------------------------------\n\n";
}

int main()
{
    HANDLE heap = HeapCreate(HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 4 * 1024 * 1024, 0);

    sh(heap); // Вывод информации о куче до выделения памяти

    {
        int* m = (int*)HeapAlloc(heap, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 300000 * sizeof(int));
        cout << "-- m = " << hex << m << " \n\n"; // Выделение памяти для массива из 300,000 целых чисел
    }

    sh(heap); // Вывод информации о куче после выделения памяти

    system("pause");
}
