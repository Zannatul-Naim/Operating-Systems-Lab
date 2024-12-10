#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    
    pid_t pid = fork();

    if(pid == 0) {
        printf("Hi, i'm child! zombie....\n");
    } else {
        sleep(50);
    }
    wait(NULL);
}