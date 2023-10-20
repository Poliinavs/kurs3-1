#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    for (int i = 0; i < 1000; i++) {
        sleep(2);
        printf("PID: %d-#%d\n", getpid(), i);
    }

    exit(0);
}
//gcc zd4.c -o zd4