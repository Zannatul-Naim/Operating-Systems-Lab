#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct Result {
    int min;
    int max;
    float average;
} result;

int n;

void *min(void *arg) {
    int i;
    int *temp = (int *)arg;
    result.min = temp[0];
    printf("Running in worker min thread …\n");
    for (i = 0; i < n; i++) {
        if (temp[i] < result.min) {
            result.min = temp[i];
        }
    }
}

void *max(void *arg) {
    int i;
    int *temp = (int *)arg;
    printf("Running in worker max thread …\n");
    for (i = 0; i < n; i++) {
        if (temp[i] > result.max) {
            result.max = temp[i];
        }
    }
}

void *average(void *arg) {
    int i;
    int *temp = (int *)arg;
    printf("Running in worker average thread …\n");
    for (i = 0; i < n; i++) {
        result.average += temp[i];
    }
    result.average = result.average / n;
}

int main(int argc, char* argv[]) {

    if(argc < 2) {
        printf("wrong input.\n");
        return 1;
    }

    n = argc - 1;
    int *arg = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        arg[i] = atoi(argv[i+1]);
    }

    pthread_t t1, t2, t3;

    printf("Worker thread started ...\n");
    pthread_create(&t1, NULL, min, (void *)arg);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, max, (void *)arg);
    pthread_join(t2, NULL);

    pthread_create(&t3, NULL, average, (void *)arg);
    pthread_join(t3, NULL);

    printf("Worker thread ended ...\n");
    printf("\nThe average is %f\nThe maximum is %d\nThe minimum is %d\n", result.average, result.max, result.min);

    return 0;
}
