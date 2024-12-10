#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h> 


void operation(int a, int b, int type) { 
    int result; 
    switch(type) { 
        case 1: 
            result = a + b; 
            printf("Child process %d for addition: %d + %d = %d\n", type, a, b, result); break; 
        case 2: 
            result = a - b; 
            printf("Child process %d for subtraction: %d - %d = %d\n", type, a, b, result); break; 
        case 3: 
            result = a * b; 
            printf("Child process %d for multiplication: %d * %d = %d\n", type, a, b, result); break; 
    } 
} 
int main() { 

    int a = 10, b = 5; 
    printf("Parent process: a = %d, b = %d\n", a, b); 
    
    for(int i = 1; i <= 3; i++) { 
        pid_t pid = fork(); 
        if(pid == 0) { 
            operation(a, b, i); 
            return(0); 
        } else if(pid > 0) {
            ("Parent process created child with pid: %d\n", pid); 
        } else { 
            printf("Fork failed\n"); 
            return 1; 
        } 
    } 
    return 0;

}