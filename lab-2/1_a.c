#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/prctl.h>
  
void handler1() {
   pid_t pid = fork();
   if(pid == 0) {
       prctl(PR_SET_NAME, "forked_process", 0, 0, 0);
       sleep(55);
   }
   else {
       sleep(55);
   }
}


void handler2() {
   sleep(35);
}


void main() {


   pthread_t tid_1, tid_2;
   pthread_create(&tid_1, NULL, (void*)handler1, NULL);
   pthread_create(&tid_2, NULL, (void*)handler2, NULL);
   pthread_join(tid_1, NULL);
   pthread_join(tid_2, NULL);
}
