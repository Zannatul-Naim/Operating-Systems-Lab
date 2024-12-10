#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    
    // fork();
    fork();
    printf("Bangladesh\n");
    fork(); 
    // fork();
    printf("Bangladesh\n");
    fork();
    // printf("Bangladesh3");
    // pid_t pid;
    // pid = fork();
    // if (pid == 0) {
    //     fork();	
    //     pthread_create(&tid, NULL, (void)thread_handler, NULL);
    //     printf("H\n");
    // }
    // fork();

}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>

// void* thread_handler(void* arg) {
//     printf("Thread is running\n");
//     return NULL;
// }

// int main() {
//     pid_t pid;
//     pthread_t tid;

//     pid = fork();
//     if (pid == 0) {
//         fork(); 
//         pthread_create(&tid, NULL, thread_handler, NULL);
//         // printf("H\n");
//     }
//     fork();
//     printf("h\n");
//     return 0;
// }