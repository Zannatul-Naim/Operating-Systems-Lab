#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0) { 
        printf("Error! Fork failed!\n");
        return 1;
    } else if (pid == 0) { // child process

        execlp("gcc", "gcc", "hello.c", "-o", "hello", NULL);  // compile a C or C++ file
            } 
    else { 

        wait(NULL);
        printf("Child Complete\n"); 
        execlp("./hello", "hello", NULL);
        // execlp("./bye", "bye", NULL);
    }
    return 0;
}
