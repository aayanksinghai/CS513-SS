/*
============================================================================
Name : 19.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 28/08/2025
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

static __inline__ uint64_t rdtsc(void) { //reading timestamp
    unsigned int low, high;
    __asm__ __volatile__ ("rdtsc" : "=a" (low), "=d" (high));
    return ((uint64_t)high << 32) | low;
}

int main() {
    uint64_t startTime, endTime;
    pid_t pid;

    startTime = rdtsc();  //time before
    pid = getpid();
    endTime = rdtsc();  //time after

    printf("PID: %d\n", pid);
    printf("Time taken by getpid(): %lu\n", (endTime - startTime));

    return 0;
}



/*
============================================================================
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P19$ cc 19.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P19$ ./a.out
PID: 12108
Time taken by getpid(): 14912

============================================================================
*/