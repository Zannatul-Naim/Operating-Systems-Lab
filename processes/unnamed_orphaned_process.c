#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main() {

	pid_t myPID, parentPID, childPID;
	int x = 5;
	
	myPID = getpid();
	parentPID = getppid();
	
	childPID = fork();
	
	if(childPID == 0) {
		pid_t myPid = getpid();
		pid_t pPid = getppid();
		for(int i = 0; i < 1000; i++) {
			printf("child\tmy : %d\t parent = %d\n", myPid, pPid);
		}
	} else {
		pid_t myPid = getpid();
		pid_t pPid = getppid();
		for(int i = 0; i < 100; i++) {
			printf("parent\tmy : %d\t parent = %d\n", myPid, pPid);
		}
		wait();
	}

	exit(0);
	
}

