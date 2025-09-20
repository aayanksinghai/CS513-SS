/*
===========================================================================================================================
Name : 3.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 20th Sept, 2025.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    
    struct rlimit rl;

    rl.rlim_cur = 1; // Soft limit
    rl.rlim_max = 2; // Hard limit

    setrlimit(RLIMIT_CPU, &rl);

    printf("CPU time limit set to 1 second.\n");
    while (1);
    return EXIT_SUCCESS;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P3$ cc 3.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P3$ ls
3.c  a.out
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P3$ ./a.out
CPU time limit set to 1 second.
CPU time limit exceeded (core dumped)
===========================================================================================================================
*/