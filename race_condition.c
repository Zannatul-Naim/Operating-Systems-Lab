#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int i = 1; 

    pid_t pid = fork();

    if(pid == 0) {
        for(; i <= 500; i++) {
            printf("Child process i = %d\n", i);
        }
        exit(0);
    } else {
        for(; i <= 500; i++) {
            printf("parent process i = %d\n", i);
        }
    }

    return 0;
}