#include <fcntl.h>
#include <unistd.h>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    char buffer[100];
    char *msg = "Hello, OS\n";
    int flag;

    /*
        O_RDWR : READ | WRITE mode
        O_CREAT: CREATE mode
        S_IRUSR: READ permissioin to the user
        S_IWUSR: WRITE permissioin to the user
    */

    int fd = open("file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        char *msg = "Error opening/creating file\n";
        write(STDOUT_FILENO, msg, strlen(msg)+1);
        exit(0);
    }

    flag = write(fd, msg, strlen(msg)+1);

    if (flag == -1) {
        char *msg = "Error writing to file\n";
        exit(0);
    }
    
    lseek(fd, 0, SEEK_SET);  // lseek: function to reposition the file pointer to the beginning of the file befor reading from it.

    int n = read(fd, buffer, sizeof(buffer));

    if (n == -1) {
        char *msg = "Error reading from file\n";
        write(STDOUT_FILENO, msg, strlen(msg)+1);
        exit(0);
    }
    buffer[n] = '\0';
    write(STDOUT_FILENO, buffer, strlen(buffer)+1);

    return 0;
}
