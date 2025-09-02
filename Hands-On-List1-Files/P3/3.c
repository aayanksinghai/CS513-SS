/*
============================================================================
Name : 3.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 24/08/2025
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <sys/stat.h>

int main() {

    const char *file_path = "file3.txt";

    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; 

    int fd = creat(file_path, mode);
    printf("File descriptor: %d\n", fd);
    return 0;
}



/*
=========================================================================================================
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P3$ cc 3.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P3$ ls
3.c  a.out
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P3$ ./a.out
File descriptor: 3
=========================================================================================================
*/
