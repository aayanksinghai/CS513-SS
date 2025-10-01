/*
===========================================================================================================================
Name : 20a.c
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

// Writer Code
int main() {
    int fd;

    // Create FIFO if it doesn't exist
    mkfifo("myfifo", 0666);

    // Open FIFO for writing
    fd = open("myfifo", O_WRONLY);

    char msg[] = "Hello from writer\n";
    write(fd, msg, sizeof(msg));
    printf("Writer: message %s", msg);

    close(fd);
    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P20$ ./20a
Writer: message Hello from writer

===========================================================================================================================
*/