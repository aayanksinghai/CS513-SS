
/*
===========================================================================================================================
Name : 10c.c
Author : Aayank Singhai (MT2025001)
Description : Write a separate program using sigaction system call to catch the following signals.
            c. SIGFPE
Date: 22nd September, 2025.
===========================================================================================================================
*/


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigfpe(int sig) {
    printf("\nFloating-Point Exception caught! Signal number: %d. Exiting cleanly.\n", sig);
    exit(EXIT_FAILURE);
}

int main() {
    struct sigaction sa = { .sa_handler = handle_sigfpe };

    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Handler installed. Program will now cause a floating-point exception...\n");

    int a = 1, b = 0;
    a = a / b;

    printf("This message will not be printed.\n");

    return 0;
}

/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P10$ cc 10c.c -o 10c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P10$ ./10c
Handler installed. Program will now cause a floating-point exception...

Floating-Point Exception caught! Signal number: 8. Exiting cleanly.
===========================================================================================================================
*/