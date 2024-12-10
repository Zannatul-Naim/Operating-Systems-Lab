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

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void main(int argc, char **argv) { // Takes pid of the signal receiver
    pid_t signal_receiver;
    signal_receiver = atoi(argv[1]);
    kill(signal_receiver, SIGKILL);
}