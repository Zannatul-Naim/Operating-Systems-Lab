#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define MAX_BUFFER_SIZE 100

int main(){
    pid_t childPID;
    int pipeFD1[2], pipeFD2[2];  // Two pipes
    int pipeFlag;
    char buffer[MAX_BUFFER_SIZE];
    int n;

    // Create two pipes
    pipeFlag = pipe(pipeFD1);  // Pipe 1 for parent -> child
    if (pipeFlag == -1){
        printf("Error occurred while creating Pipe 1 for communication.\n");
        exit(-1);
    }

    pipeFlag = pipe(pipeFD2);  // Pipe 2 for child -> parent
    if (pipeFlag == -1){
        printf("Error occurred while creating Pipe 2 for communication.\n");
        exit(-1);
    }

    // Fork the process
    childPID = fork();
    if (childPID == -1){
        printf("Error occurred while creating a process.\n");
        exit(-1);
    }
    else if (childPID == 0){
        // Child Process

        close(pipeFD1[0]);  // Close the read end of Pipe 1
        close(pipeFD2[1]);  // Close the write end of Pipe 2

        // Chat loop for the child
        while (1) {
            // Read message from the parent (Pipe 2)
            n = read(pipeFD2[0], buffer, sizeof(buffer));
            if (n <= 0) break; // Exit if no more data
            buffer[n] = '\0';  // Null-terminate the buffer
            printf("Child received: %s\n", buffer);

            // Get input from child and send to parent (Pipe 1)
            printf("Child: Enter your message to send to Parent: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';  // Remove the newline

            if (strcmp(buffer, "exit") == 0) {
                break;
            }

            write(pipeFD1[1], buffer, strlen(buffer));  // Send message to parent
        }

        close(pipeFD1[1]);  // Close after writing to Pipe 1
        close(pipeFD2[0]);  // Close after reading from Pipe 2
    }
    else {
        // Parent Process

        close(pipeFD1[1]);  // Close the write end of Pipe 1
        close(pipeFD2[0]);  // Close the read end of Pipe 2

        // Chat loop for the parent
        while (1) {
            // Get input from parent and send to child (Pipe 2)
            printf("Parent: Enter your message to send to Child: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';  // Remove the newline

            if (strcmp(buffer, "exit") == 0) {
                break;
            }

            write(pipeFD2[1], buffer, strlen(buffer));  // Send message to child

            // Read message from the child (Pipe 1)
            n = read(pipeFD1[0], buffer, sizeof(buffer));
            if (n <= 0) break;  // Exit if no more data
            buffer[n] = '\0';  // Null-terminate the buffer
            printf("Parent received: %s\n", buffer);
        }

        close(pipeFD1[0]);  // Close after reading from Pipe 1
        close(pipeFD2[1]);  // Close after writing to Pipe 2

        wait(NULL);  // Wait for the child process to finish
    }

    exit(0);
}
