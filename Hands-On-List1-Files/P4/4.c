/*
============================================================================
Name : 4.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 24/08/2025
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h> 

int main() {

    const char *file_path = "4.txt";  
    int fd = open(file_path, O_RDWR | O_EXCL);	// If we use O_CREAT | O_EXCL, it works exclusively, meaning fd will return -1 due to file being present, else if file does not exist, it creates new file and return fd. If used O_CREAT without O_EXCL, it will return fd whether file is present or not

    if (fd == -1) {
        perror("Error opening file\n");
        return 1;
    }else{
        printf("Successfully opened file with Read and Write mode\n");
    }

    printf("File Descriptor Value: %d\n", fd);
    return 0;
}


/*
=========================================================================================================
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P4$ cc 4.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P4$ ./a.out
Successfully opened file with Read and Write mode
File Descriptor Value: 3
=========================================================================================================
*/
