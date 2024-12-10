#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_child_process(char *child_name) {
    printf("Creating process: %s\n", child_name);
    pid_t pid = fork();

    if (pid < 0) {
        perror("Failed to fork");
        exit(1);
    } else if (pid == 0) {
        execlp("sh", "sh", "-c", child_name, (char *)NULL);
        perror("execlp failed");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <number_of_children> <child_1> <child_2> ... <child_n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1 || argc != n + 2) {
        fprintf(stderr, "Error: Please provide a valid number of child processes and their names.\n");
        return 1;
    }

    printf("Parent process (PID: %d) is creating %d child processes...\n", getpid(), n);

    for (int i = 0; i < n; i++) {
        create_child_process(argv[i + 2]);
    }

    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("All child processes completed.\n");

    printf("\nProcess tree:\n");
    system("pstree -p");

    return 0;
}
