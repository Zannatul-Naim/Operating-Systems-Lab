#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Received: UserThread1\n");
    }
}

void *thread_2_receiver(void *arg) {
    sleep(10);
    signal(SIGUSR1, signal_handler);

    printf("Thread 2 receiver thread Waiting for signal...\n");
    while (1) {
        pause();
    }

    return NULL;
}

void *thread_1_sender(void *arg) {
    pthread_t *receiver_tid = (pthread_t *)arg;

    sleep(10);
    printf("Thread 1 sender thread Sending signal (SIGUSR1) to thread 2 receiver thread\n");

    pthread_kill(*receiver_tid, SIGUSR1);

    return NULL;
}

int main() {
    pthread_t tid1, tid2;

    if (pthread_create(&tid1, NULL, thread_2_receiver, NULL) != 0) {
        printf("Thread creation failed\n");
        return 1;
    }

    if (pthread_create(&tid2, NULL, thread_1_sender, &tid1) != 0) {
        printf("Thread creation failed\n");
        return 1;
    }
    pthread_join(tid2, NULL);
    pthread_cancel(tid1);

    printf("Program completed. (Main Thread) \n");
    return 0;
}
