#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {

    pid_t child_pid = fork();

    int n;

    if(child_pid == 0) {
        n = 1; 
    } else {
        n = 6;
       wait(NULL);
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", i);
    } 
    printf("\n");
}