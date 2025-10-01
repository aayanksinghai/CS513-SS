/*
===========================================================================================================================
Name : 8c.c
Author : Aayank Singhai (MT2025001)
Description : Write a separate program using signal system call to catch the following signals.
            c. SIGFPE
Date: 20th September, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigfpe(int sig) {
    printf("\nCaught SIGFPE");
    exit(1);
}

int main() {
    
    signal(SIGFPE, handle_sigfpe);

    int x = 1 / 0;

    return 0;
}


/*
OUTPUT
===========================================================================================================================
-Files/P8$ cc 8c.c -o 8c
8c.c: In function ‘main’:
8c.c:24:15: warning: division by zero [-Wdiv-by-zero]
   24 |     int x = 1 / 0;
===========================================================================================================================
*/


