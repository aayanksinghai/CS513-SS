/*
===========================================================================================================================
Name : 8c.c
Author : Aayank Singhai
Description : Write a separate program using signal system call to catch the following signals.
            e. SIGALRM (use setitimer system call)
Date: 20th September, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigALRM(int sig) {
    printf("Caught SIGALRM\n");
}

int main() {

    struct itimerval timer;
    signal(SIGALRM, sigALRM);

    // Set timer for 3 seconds, no repeating
    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    printf("Waiting for the alarm...\n");
    pause();
    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P8$ ./8e
Waiting for the alarm...
Caught SIGALRM
===========================================================================================================================
*/


