/*
============================================================================
Name : 9.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 21st September, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
    printf("Ignoring SIGINT signal\n");
    signal(SIGINT, SIG_IGN);
    // CTRL + C is ignored.
    sleep(7);
    printf("\nDefault action of SIGINT signal\n");
    signal(SIGINT, SIG_DFL);
    // CTRL + C is no longer ignored.
    sleep(7);
    return(0);
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P9$ cc 9.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P9$ ./a.out
Ignoring SIGINT signal
^C^C^C^C^C^C
Default action of SIGINT signal
^C
===========================================================================================================================
*/