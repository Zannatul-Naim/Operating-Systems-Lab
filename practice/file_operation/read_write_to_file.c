#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDWR | O_CREAT | O_APPEND, 0666);

    if(fd == -1) {
        printf("fild creat | open failed\n");
        return 1;
    }

    char *msg = "new file opeartion ";
    ssize_t bytes_write = write(fd, msg, strlen(msg));

    if(bytes_write == -1) {
        printf("write failed!\n");
        close(fd);
        return 1;
    }

    lseek(fd, 0, SEEK_SET);

    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));

    if(bytes_read == -1) {
        printf("read failed\n");
        close(fd);
        return 1;
    }

    buffer[bytes_read] = '\0';

    write(STDOUT_FILENO, buffer, strlen(buffer));
    write(STDOUT_FILENO, "\n", 1);

    close(fd);

    return 0;
}