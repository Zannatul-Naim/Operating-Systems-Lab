#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    
    pid_t pid = fork();

    if(pid == 0) {
        sleep(10);
        printf("Hi, i'm child! zombie....\n process id: %d\nparent id: \n", getpid(), getppid(pid));
    } else {
        printf("parent ... id: %d\n", getpid());
    }
    // wait(NULL);
}