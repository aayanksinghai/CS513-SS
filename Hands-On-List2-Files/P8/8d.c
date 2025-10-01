/*
===========================================================================================================================
Name : 8d.c
Author : Aayank Singhai (MT2025001)
Description : Write a separate program using signal system call to catch the following signals.
            d. SIGALRM (use alarm system call)
Date: 20th September, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigALRM(int sig) {
    printf("Caught SIGALRM\n");
}

int main() {

    signal(SIGALRM, sigALRM);
    
    alarm(3); 

    printf("Waiting for the alarm...\n");
    pause();

    return 0;
}

/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P8$ cc 8d.c -o 8d
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P8$ ./8d
Waiting for the alarm...
Caught SIGALRM
===========================================================================================================================
*/


