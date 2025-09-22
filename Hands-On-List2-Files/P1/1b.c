/*
===========================================================================================================================
Name : 1b.c
Author : Aayank Singhai (MT2025001)
Description : 1.  Write a separate program (for each time domain) to set a interval timer in 10sec and 
10micro second                
b. ITIMER_VIRTUAL        
Date: 22nd Sept, 2025.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void handle_t(int signum) {
    printf("Timer expired! (ITIMER_VIRTUAL)\n");
}

int main() {

    struct itimerval timer;
    signal(SIGVTALRM, handle_t);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    // Configure the timer to reset to the same interval
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while (1);
    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P1$ cc 1b.c -o 1b
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P1$ ./1b
Timer expired! (ITIMER_VIRTUAL)
Timer expired! (ITIMER_VIRTUAL)
Timer expired! (ITIMER_VIRTUAL)
Timer expired! (ITIMER_VIRTUAL)
Timer expired! (ITIMER_VIRTUAL)

===========================================================================================================================
*/