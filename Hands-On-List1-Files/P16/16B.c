/*
============================================================================
Name : 16B.c
Author : Aayank Singhai (MT2025001)
Description : 16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock ***
Date: 28/08/2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(){

        struct flock fm;
        char s[100];
        int fq = open("16b.txt", O_RDWR | O_CREAT, 0666);
        fm.l_type = F_RDLCK;
        fm.l_whence = SEEK_SET;
        fm.l_start = 0;
        fm.l_len = 0;
        fm.l_pid = getpid();

        printf("Before locking the file for reading\n");
        fcntl(fq, F_SETLKW, &fm);
        printf("Read lock acquired successfully....\n");
        printf("Press a key to unlock...\n");
        getchar();

        fm.l_type = F_UNLCK;
        fcntl(fq, F_SETLK, &fm);
        printf("Finish\n");
        return 0;
}




/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P16$ ./16B 16b.txt
Before locking the file for reading
Read lock acquired successfully....
Press a key to unlock...

Finish


============================================================================
*/