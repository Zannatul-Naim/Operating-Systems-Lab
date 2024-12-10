#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main() {
    
    pid_t p1, p2;

    p1 = fork();

    if(p1 < 0) {
        fprintf(stderr, "Fork failed");
        return;
    } else if(p1 == 0) {
        p2 = getpid();
        printf("Child: pid = %d\n", p1);
        printf("child: pid1 = %d\n", p2);
    } else {
        p2 = getpid();
        printf("parent: pid = %d\n", p1);
        printf("parent: pid1 = %d\n", p2);
    }

    return;
}
