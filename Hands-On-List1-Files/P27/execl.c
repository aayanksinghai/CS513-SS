/*
============================================================================
Name : execl.c
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

    printf("===== Output using execl =====\n");
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);
    printf("\n");
    return 0;
}





/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P27$ cc execl.c -o execl
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P27$ ls
execl  execl.c  execled.c  execlp.c  execv.c  execvp.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P27$ ./execl
===== Output using execl =====
.:
total 36
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16048 Sep  5 11:48 execl
-rw-rw-r-- 1 aayanksinghai aayanksinghai   729 Sep  5 11:48 execl.c
-rw-rw-r-- 1 aayanksinghai aayanksinghai   524 Sep  5 11:44 execled.c
-rw-rw-r-- 1 aayanksinghai aayanksinghai   524 Sep  5 11:44 execlp.c
-rw-rw-r-- 1 aayanksinghai aayanksinghai   524 Sep  5 11:44 execv.c
-rw-rw-r-- 1 aayanksinghai aayanksinghai   524 Sep  5 11:44 execvp.c

============================================================================
*/
