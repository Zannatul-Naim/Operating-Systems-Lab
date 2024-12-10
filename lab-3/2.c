#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <wait.h>

struct fib {
    int n;
    int arr[100000];
};

void *fibonacci(struct fib *f) {
    printf("The thread is running ...\n");
    // struct fib *f = ((struct fib *)a);
    if (f->n == 1) {
        f->arr[0] = 0;
    }
    if (f->n == 2) {
        f->arr[0] = 0;
        f->arr[1] = 1;
    } else {
        f->arr[0] = 0;
        f->arr[1] = 1;
        int i;
        for (i = 2; i < f->n; i++) {
            f->arr[i] = f->arr[i - 1] + f->arr[i - 2];
        }
    }
}
int main() {

    struct fib f;
    printf("Enter the number: ");
    scanf("%d", &f.n);
    printf("\n");

    pthread_t thread;
    printf("Before the thread run ...\n");
    
    pthread_create(&thread, NULL, fibonacci, &f);
    
    wait(NULL);
    
    pthread_join(thread, NULL);

    printf("After the thread run ...\n");
    printf("Output fibonacci sequence for %d: ", f.n);
    
    for (int i = 0; i < f.n; i++) {
        printf("%d ", f.arr[i]);
    }

    printf("\n");
    return 0;
}
