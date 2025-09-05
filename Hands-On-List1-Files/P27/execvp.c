/*
============================================================================
Name : execvp.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle. execv
e. execvp
Date: 30/08/2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("======== Output using execvp ========== \n");
    char *argv[] = {"ls", "-Rl", NULL};
    execvp("ls", argv);
    printf("\n");
    return 0;
}


/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P27$ ./execvp
======== Output using execvp ========== 
.:
total 116
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:48 execl
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1571 Sep  5 11:53 execl.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:52 execle
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1327 Sep  5 11:53 execle.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:51 execled
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:54 execlp
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1401 Sep  5 11:54 execlp.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16056 Sep  5 11:55 execv
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1470 Sep  5 11:56 execv.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16096 Sep  5 11:57 execvp
-rw-rw-r-- 1 aayanksinghai aayanksinghai   752 Sep  5 11:56 execvp.c

============================================================================
*/
