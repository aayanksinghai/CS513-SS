
/*
===========================================================================================================================
Name : 10a.c
Author : Aayank Singhai (MT2025001)
Description : Write a separate program using sigaction system call to catch the following signals.
            a. SIGSEGV
Date: 22nd September, 2025.
===========================================================================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigsegv(int sig) {
    printf("\nSegmentation Fault caught! Signal number: %d. Exiting cleanly.\n", sig);
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa = { .sa_handler = handle_sigsegv };

    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Handler installed. Program will now cause a segmentation fault...\n");

    int *ptr = NULL;
    *ptr = 42;

    printf("This message will not be printed.\n");

    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P10$ cc 10a.c -o 10a
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P10$ ./10a
Handler installed. Program will now cause a segmentation fault...

Segmentation Fault caught! Signal number: 11. Exiting cleanly.

===========================================================================================================================
*/