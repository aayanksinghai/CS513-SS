/*
============================================================================
Name : execle.c
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
    printf("===== Output using execled ======\n");
    execle("/bin/ls", "ls", "-Rl", (char *)NULL, NULL);
    printf("\n");
    return 0;
}




/*
============================================================================
OUTPUT

===== Output using execled ======
.:
total 68
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:48 execl
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1572 Sep  5 11:49 execl.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:52 execle
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1261 Sep  5 11:52 execle.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:51 execled
-rw-rw-r-- 1 aayanksinghai aayanksinghai   524 Sep  5 11:44 execlp.c
-rw-rw-r-- 1 aayanksinghai aayanksinghai   524 Sep  5 11:44 execv.c
-rw-rw-r-- 1 aayanksinghai aayanksinghai   524 Sep  5 11:44 execvp.c

============================================================================
*/
