/*
============================================================================
Name : 12.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 26/08/2025
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void file_mode(int flags) {

    printf("File mode: ");

    if (flags & O_RDONLY) printf("Opened in Read-only\n");
    if (flags & O_WRONLY) printf("Opened in Write-only\n");
    if (flags & O_RDWR)   printf("Opened in Read and Write\n");
}

int main() {
    const char *file = "12.txt";  
    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    file_mode(flags);

    close(fd);
    return 0;
}


/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P12$ cc 12.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P12$ ./a.out
File mode: Opened in Write-only
============================================================================
*/
