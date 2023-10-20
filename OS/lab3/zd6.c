#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    system("./zd6_1");  
    for (int i = 0; i < 100; i++) {
        sleep(1);
        printf("zd6 PID: %d-#%d\n", getpid(), i);
    }

    exit(0);
}