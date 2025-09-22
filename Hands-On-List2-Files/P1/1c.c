/*
===========================================================================================================================
Name : 1c.c
Author : Aayank Singhai (MT2025001)
Description : 1.  Write a separate program (for each time domain) to set a interval timer in 10sec and 
10micro second               
c. ITIMER_PROF 
Date: 22nd Sept, 2025.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void handle_t(int signum) {
    printf("Timer expired! (ITIMER_PROF)\n");
}

int main() {

    struct itimerval timer;
    signal(SIGPROF, handle_t);
    
    // Configure the timer to expire after 10 seconds and 10 microseconds
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    // Configure the timer to reset to the same interval
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_PROF, &timer, NULL);
    while (1);

    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P1$ cc 1c.c -o 1c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P1$ ./1c
Timer expired! (ITIMER_PROF)
Timer expired! (ITIMER_PROF)
Timer expired! (ITIMER_PROF)
Timer expired! (ITIMER_PROF)

===========================================================================================================================
*/