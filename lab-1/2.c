#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() { 

    int pid = fork(); 
    
    if (pid > 0) { 
        printf("In parent process with pid: %d\n", getpid());
        sleep(10); 
    } else if (pid == 0) { 
        printf("In child process with pid: %d\n", getpid()); 
        sleep(30); 
    } 
    return 0; 
} 