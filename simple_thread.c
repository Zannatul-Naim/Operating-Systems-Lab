#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int x = 5, y = 4;
int result;

int sum() {
    // int result;
    for(int i = 0; i < 150; i++) {
        printf("pre-result : %d\t", result);
        result += x+y;
        printf("thread-1 :\tx + y = %d\n", result);
    }
}

int sub() {
    // int result;
    for(int j = 0; j < 150; j++) {
        printf("pre-result : %d\t", result);
        result += x-y;
        printf("thread-2 :\tx - y = %d\n", result);
    }
}

int main() {
    // sum();
    // sub();
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, (void *)sum, NULL);
    pthread_create(&tid2, NULL, (void *)sub, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    exit(EXIT_SUCCESS);
}
