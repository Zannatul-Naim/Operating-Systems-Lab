/*
1. First compile and run the signal_receiver.c {Assuming pid of signal_receiver is 17559}
2. Compile signal_sender.c [gcc signal_sender.c -o signal_sender]
3. Run signal_sender from command line [./signal_sender 17559]

A sample output:

1: PID: 17559
2: PID: 17559
3: PID: 17559
4: PID: 17559
I have received the SIGTERM signal. Terminating gracefully.
Terminating...
Terminating...
Terminating...
Terminated.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void signal_handler(int signal) {
    if(signal == SIGKILL) {
        printf("I have received the SIGTERM signal. Terminating gracefully.\n");
        sleep(1);
        // for(int i = 0; i < 3; i++) {
        //     printf("Terminating...\n");
        //     sleep(1);
        // }
        // printf("Terminated.\n");
        // exit(0);
    }
}

int main() {
    pid_t pid = getpid();
    signal(SIGKILL, signal_handler); // Only the SIGTERM is handled, others will have default behavior
    for(int i = 1; i < 100; i++) {
        printf("%d: PID: %d\n", i, pid);
        sleep(2);
    }
    return 0;
}