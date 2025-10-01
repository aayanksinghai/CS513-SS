/*
===========================================================================================================================
Name : 20b.c
Author : Aayank Singhai (MT2025001)
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 1st October, 2025
===========================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

// Reader Code
int main() {
    int fd;

    // Create FIFO if it doesn't exist
    mkfifo("myfifo", 0666);

    // Open FIFO for reading
    fd = open("myfifo", O_RDONLY);

    char buf[100];
    int n = read(fd, buf, sizeof(buf) - 1);
    if (n > 0) {
        buf[n] = '\0';  // null terminate
        printf("Reader: message %s", buf);
    } else {
        printf("Reader: no data received\n");
    }

    close(fd);
    return 0;
}

/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P20$ ./20b
Reader: message Hello from writer

===========================================================================================================================
*/