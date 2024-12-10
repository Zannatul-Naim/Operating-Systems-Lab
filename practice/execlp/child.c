#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    
    printf("Hello from child\n");
    sleep(10);
}