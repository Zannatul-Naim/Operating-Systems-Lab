#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main() {

    // decleare local variables
    char *msg;
    char buffer[100];

    int n, c;

    // write to standart output device (i.e., monitor)
    msg = "Insert a number: ";
    write(STDOUT_FILENO, msg, strlen(msg)+1);

    // read from standard input device (i.e., keyboard)
    // and keep into a buffer
    n = read(STDIN_FILENO, buffer, sizeof(buffer));
    buffer[n] = '\0';

    // write what is in buffer into standard output device
    write(STDOUT_FILENO, buffer, strlen(buffer));

    // printf("%s\n", buffer);
    // printf("%s\n", msg);

    return 0;
}
