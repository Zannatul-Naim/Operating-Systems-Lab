#define _GNU_SOURCE
#include <unistd.h>
#include <sched.h>
#include <stdio.h>
#include <wait.h>
#include <pthread.h>
#include <string.h>
#include <sys/resource.h>

int main() {
	int coreNo, priority;

	coreNo = sched_getcpu();
	priority = getpriority(PRIO_PROCESS, 0);
	printf("Logical Processor: %d, Priority: %d\n", coreNo, priority);

	nice(5);	
	priority = getpriority(PRIO_PROCESS, 0);
	printf("Logical Processor: %d, Priority: %d\n", coreNo, priority);

	setpriority(PRIO_PROCESS, 0, 15);	
	priority = getpriority(PRIO_PROCESS, 0);
	printf("Logical Processor: %d, Priority: %d\n", coreNo, priority);

	// setpriority(PRIO_PROCESS, 0, 10);
	nice(-4);	
	priority = getpriority(PRIO_PROCESS, 0);
	printf("Logical Processor: %d, Priority: %d\n", coreNo, priority);
			
	return 0;
}