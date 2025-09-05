/*
============================================================================
Name : 29.c
Author : Aayank Singhai (MT2025001)
Description : WWrite a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 30/08/2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current policy: SCHED_OTHER\n");
            break;
        default:
            printf("Current policy: Unknown\n");
            break;
    }
}

int main() {
    int policy;
    struct sched_param param;

    // Get current scheduling policy
    policy = sched_getscheduler(getpid());
    print_policy(policy);

    // Set the scheduling policy to SCHED_FIFO
    param.sched_priority = 10; 
    if (sched_setscheduler(getpid(), SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler SCHED_FIFO");
        exit(EXIT_FAILURE);
    }

    printf("Changed scheduling policy to SCHED_FIFO\n");

    policy = sched_getscheduler(getpid());
    print_policy(policy);

    // Set the scheduling policy back to SCHED_RR
    param.sched_priority = 10; 
    if (sched_setscheduler(getpid(), SCHED_RR, &param) == -1) {
        perror("sched_setscheduler SCHED_RR");
        exit(EXIT_FAILURE);
    }
    printf("Changed scheduling policy to SCHED_RR\n");
    policy = sched_getscheduler(getpid());
    print_policy(policy);
    return 0;
}


/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P29$ ./a.out
Current policy: SCHED_OTHER
sched_setscheduler SCHED_FIFO: Operation not permitted
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P29$ sudo ./a.out
[sudo] password for aayanksinghai: 
Current policy: SCHED_OTHER
Changed scheduling policy to SCHED_FIFO
Current policy: SCHED_FIFO
Changed scheduling policy to SCHED_RR
Current policy: SCHED_RR

============================================================================
*/
