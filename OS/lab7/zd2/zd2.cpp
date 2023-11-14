#include <ctime>
#include <iostream>


int main()
{
    clock_t t1 = clock();
    int i = 0;
    bool flag1 = true;

    while (true) {
        i++;
        clock_t t2 = clock();
        if (t2 - t1 == 5000 && flag1) {
            std::cout <<"iteration amount 5s: " << i << std::endl;
            flag1 = false;
        }
        if (t2 - t1 == 10000 && !flag1) {
            std::cout << "iteration amount 10s: " << i << std::endl;
            flag1 = true;
        }
        if (t2 - t1 == 15000) {
            std::cout << "iteration amount 15s: " << i << std::endl;
            break;
        }
    }
    system("pause");
}