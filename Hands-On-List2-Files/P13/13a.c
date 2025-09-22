/*
============================================================================
Name : 13a.c
Author : Aayank Singhai (MT2025001)
Description : Two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not. (First).
Date: 22nd September, 2025
============================================================================
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <bits/sigaction.h>

void catch (int sig)
{
    printf("Signal Caught - %d\n", sig);
    exit(0);
}

int main() {

    printf("The PID of process: %d\n", getpid());

    struct sigaction ac;
    memset(&ac, 0, sizeof(ac));
    
    ac.sa_handler = catch; // The handler will be ignored, as SIGSTOP and SIGKILL can not be caught.
    for (;;)
    {
        sigaction(SIGSTOP, &ac, NULL);
    }
    return (0);
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P13$ cc 13a.c -o 13a
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P13$ cc 13b.c -o 13b
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P13$ ./13a
The PID of process: 7377

[1]+  Stopped                 ./13a


In another terminal 

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P13$ ./13b
Enter pid of process to stop: 
7377
Sending SIGSTOP signal to process: 7377
SIGSTOP signal sent
Exiting current process (sender)
===========================================================================================================================
*/