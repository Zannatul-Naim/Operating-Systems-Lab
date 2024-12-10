#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 

int main() { 

    pid_t pid; 
    pid = fork(); 

    if(pid < 0) { 
        printf("Error to fork\n"); 
        exit(EXIT_FAILURE); 
    } if (pid > 0) { 
        printf("parent with pid: %d\n", getpid()); 
        sleep(120); 
    } else { 
        printf("Child process with pid: %d\n", getpid()); 
        exit(0); 
    } 
    return 0;
}