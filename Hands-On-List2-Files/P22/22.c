/*
===========================================================================================================================
Name : 22.c
Author : Aayank Singhai
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 1st October, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main(){

    char buffer[100];
    int fd = open("fifo_22", O_RDONLY | O_NONBLOCK);

    fd_set fds; 
    FD_ZERO(&fds); 
    FD_SET(fd, &fds);
    struct timeval tv = {10, 0};

    if (select(fd + 1, &fds, NULL, NULL, &tv) > 0) {
        read(fd, buffer, sizeof(buffer));
        printf("Received: %s\n", buffer);
    }else 
        printf("Timeout or error\n");

    close(fd);
    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P22$ echo "Hello fifo" > fifo_22
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P22$ ./a.out
Received: Hello fifo
===========================================================================================================================
*/