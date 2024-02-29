#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;

    /* fork a child process */
    pid = fork();

    if (pid < 0) {  // forking failed
        printf("Error! Fork failed!\n");
        return 1;
    } else if (pid == 0) { // child process

        execlp("gcc", "gcc", "hello.c", "-o", "hello", NULL);  // compile a C or C++ file
        
        // execlp("g++", "g++", "bye.cpp", "-o", "bye", NULL);  // compile a C or C++ file
    } else { // parent process

    /* parent will wait for the child to complete */
        wait(NULL);
        printf("Child Complete\n");  // child complete message
        execlp("./hello", "hello", NULL);  // run the compiled file which was compiled by child process
        
        // execlp("./bye", "bye", NULL);  // run the compiled file which was compiled by child process
    }
    return 0;
}
