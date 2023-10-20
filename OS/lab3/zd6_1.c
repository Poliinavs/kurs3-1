#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	for (int i = 0; i < 50; i++) {
		sleep(1);
		printf("zd6_1 PID: %d-#%d\n", getpid(), i);
	}

	exit(0);
}