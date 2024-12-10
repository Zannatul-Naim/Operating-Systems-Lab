#include <stdio.h>
#include <pthread.h>

#define NUM_INCREMENTS 1000000


int counter = 0;

void *increment_counter(void *param) {
   for (int i = 0; i < NUM_INCREMENTS; i++) {
       counter++;
       printf("counter value: %d\n", counter);
   }
   return NULL;
}

int main() {

   pthread_t tid1, tid2;

    if (pthread_create(&tid1, NULL, increment_counter, NULL) != 0) {
           printf("Error creating thread 1\n");
           return 1;
       }
    if (pthread_create(&tid2, NULL, increment_counter, NULL) != 0) {
           printf("Error creating thread 2\n");
           return 1;
       }
   pthread_join(tid1, NULL);
   pthread_join(tid2, NULL);



   printf("Expected counter value: %d\n", 2 * NUM_INCREMENTS);
   printf("Actual counter value: %d\n", counter);


   return 0;
}
