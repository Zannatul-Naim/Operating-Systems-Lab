#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    if (execlp("/usr/bin/ls", "ls", NULL) == -1) {
        perror("This line will executed if any error occured.\n");
        exit(1);
    }

    // Instructions after execlp() are not executed
    printf("This line will not be executed.\n");

    return 0;
}