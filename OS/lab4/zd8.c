#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>
void* OS04_07_T1(void* arg) {
    pthread_t thread_id = pthread_self();
    pid_t pid = syscall(SYS_gettid);
    for (int i = 0; i < 75; i++) {
        printf("Thread: %d - #%d\n", pid, i);
        sleep(1);
        if (i==10) {
            printf("Thread sleep \n");
            sleep(10);
        }
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    // Создаем поток
    if (pthread_create(&thread_id, NULL, OS04_07_T1, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    pid_t pid1 = syscall(SYS_gettid);

    for (int i = 0; i < 100; i++) {
        printf("Thread1: %d - #%d\n", pid1, i);
        if (i==3) {
            printf("main sleep \n");
            sleep(15);
        }


        sleep(1);
    }

    // Ожидаем завершения потока
    if (pthread_join(thread_id, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    return 0;
}
