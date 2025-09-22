
/*
===========================================================================================================================
Name : 10b.c
Author : Aayank Singhai (MT2025001)
Description : Write a separate program using sigaction system call to catch the following signals.
            b. SIGINT
Date: 22nd September, 2025.
===========================================================================================================================
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handle_sigint(int sig) {
    printf("\nSIGINT signal (%d) caught! Ignoring. Press Ctrl+\\ to quit.\n", sig);
}

int main() {

    struct sigaction sa;
    sa.sa_handler = handle_sigint;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("PID: %d. Waiting for SIGINT (Ctrl+C)...\n", getpid());

    while (1) {
        pause();
    }
    
    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P10$ cc 10b.c -o 10b
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P10$ ./10b
PID: 6531. Waiting for SIGINT (Ctrl+C)...
^C
SIGINT signal (2) caught! Ignoring. Press Ctrl+\ to quit.
^\Quit

===========================================================================================================================
*/