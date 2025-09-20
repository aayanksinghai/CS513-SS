/*
===========================================================================================================================
Name : 8a.c
Author : Aayank Singhai
Description : Write a separate program using signal system call to catch the following signals.
            a. SIGSEGV
Date: 20th September, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void segmentation_fault(int sig) {
    printf("Segmentation Fault\n");
    exit(1);
}

int main() {

    signal(SIGSEGV, segmentation_fault);

    int *p = NULL;
    *p = 10;

    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P8$ cc 8a.c -o 8a
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P8$ ./8a
Segmentation Fault
===========================================================================================================================
*/


