/*
===========================================================================================================================
Name : 14.c
Author : Aayank Singhai (MT2025001)
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 2nd Sept, 2025.
===========================================================================================================================
*/


#include  <stdio.h>
#include  <unistd.h>
#include  <string.h>

int main(void){
    int fd[2];
    char buff[100];

    char *message = "Hello My Name is Aayank\n";
    pipe(fd);

    write(fd[1], message, strlen(message));
    int bytes_read = read(fd[0], buff, sizeof(buff));
    buff[bytes_read] = '\0';
    printf("Read from Pipe: %s\n", buff);
    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P14$ ./a.out
Read from Pipe: Hello My Name is Aayank
===========================================================================================================================
*/
