#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>

void *thread_function(void *arg) {
    int cpu = sched_getcpu(); 
    printf("Thread is running on CPU %d\n", cpu);

    // Do some work
    for (int i = 0; i < 5; i++) {
        printf("Thread working on CPU %d...\n", cpu);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread;
    cpu_set_t cpuset;

    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("Failed to create thread");
        exit(1);
    }

    CPU_ZERO(&cpuset); 
    CPU_SET(0, &cpuset);

    if (pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset) != 0) {
        perror("Failed to set thread affinity");
        exit(1);
    }

    if (pthread_getaffinity_np(thread, sizeof(cpu_set_t), &cpuset) != 0) {
        perror("Failed to get thread affinity");
        exit(1);
    }

    printf("Thread affinity set to CPUs: ");
    for (int i = 0; i < CPU_SETSIZE; i++) {
        if (CPU_ISSET(i, &cpuset)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("size: %d\n", sizeof(cpu_set_t));

    pthread_join(thread, NULL);

    return 0;
}
