/*
============================================================================
Name : execlp.c
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

    printf("======== Output using execlp =============\n");
    execlp("ls", "ls", "-Rl", (char *)NULL);
    printf("\n");
    return 0;
}




/*
============================================================================
OUTPUT
======== Output using execlp =============
.:
total 84
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:48 execl
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1571 Sep  5 11:53 execl.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:52 execle
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1327 Sep  5 11:53 execle.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:51 execled
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:54 execlp
-rw-rw-r-- 1 aayanksinghai aayanksinghai   735 Sep  5 11:54 execlp.c
-rw-rw-r-- 1 aayanksinghai aayanksinghai   522 Sep  5 11:53 execv.c
-rw-rw-r-- 1 aayanksinghai aayanksinghai   522 Sep  5 11:53 execvp.c

============================================================================
*/
