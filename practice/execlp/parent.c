#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    
    pid_t pid = fork();

    if(pid == 0) {
        execlp("./child", "child", NULL);
    } else {
        // sleep(2);
        printf("parent completed!\n");
    }
    // wait(NULL);
}