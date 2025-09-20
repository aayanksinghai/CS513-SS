/*
===========================================================================================================================
Name : 8b.c
Author : Aayank Singhai
Description : Write a separate program using signal system call to catch the following signals.
            b. SIGINT
Date: 20th September, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigINT(int sig) {
    printf("Caught SIGINT\n");
    exit(0);
}

int main() {

    signal(SIGINT, sigINT);

    while (1) {
        printf("Process is running... \n Press Ctrl+C to stop\n");
        sleep(1);
    }

    return 0;
}

/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P8$ cc 8b.c -o 8b
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P8$ ./8b
Process is running... 
 Press Ctrl+C to stop
Process is running... 
 Press Ctrl+C to stop
Process is running... 
 Press Ctrl+C to stop
Process is running... 
 Press Ctrl+C to stop
^CCaught SIGINT
===========================================================================================================================
*/


