/*
===========================================================================================================================
Name : 23.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 1st October, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    printf("Max number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Pipe size: %ld bytes\n", fpathconf(STDIN_FILENO, _PC_PIPE_BUF));

    return 0;
}

/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P23$ cc 23.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P23$ ./a.out
Max number of open files: 1048576
Pipe size: 4096 bytes
===========================================================================================================================
*/