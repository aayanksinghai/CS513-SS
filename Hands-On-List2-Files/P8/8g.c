/*
===========================================================================================================================
Name : 8c.c
Author : Aayank Singhai (MT2025001)
Description : Write a separate program using signal system call to catch the following signals.
            g. SIGPROF (use setitimer system call)
Date: 20th September, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handle_sigprof(int sig) {
    printf("Caught SIGPROF: Profiling timer expired\n");
}

int main() {

    struct itimerval timer;
    signal(SIGPROF, handle_sigprof);

    // Set profiling timer for 3 seconds
    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    printf("Waiting for profiling timer alarm...\n");
    for (long long i = 0; i < 1e10; ++i);
    pause();  // Wait for signal

    return 0;
}



/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P8$ cc 8g.c -o 8g
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P8$ ./8g
Waiting for profiling timer alarm...
Caught SIGPROF: Profiling timer expired
===========================================================================================================================
*/


