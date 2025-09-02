/*
===========================================================================================================================
Name : 15.c
Author : Aayank Singhai (MT2025001)
Description : Write a simple program to send some data from parent to the child process.
Date: 2nd Sept, 2025.
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void){
    int fd[2];
    char buff[100];

    pipe(fd);

    if(fork()){
        close(fd[0]);
        char *message = "Hello My Name is Aayank\n";
        write(fd[1], message, strlen(message));

    }else{
        close(fd[1]);
        read(fd[0], buff, sizeof(buff));
        printf("Reading data sent from parent to child: %s\n", buff);
    }
    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P15$ ./a.out
Reading data sent from parent to child: Hello My Name is Aayank
===========================================================================================================================
*/