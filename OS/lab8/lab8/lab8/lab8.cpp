// lab8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>

int main()
{
    for (int i = 0; i < 10000; i++)
    {
        std::cout << i << std::endl;
        Sleep(1000);
    }
    system("pause");
}