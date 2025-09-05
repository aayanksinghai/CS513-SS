/*
============================================================================
Name : 30.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 30/08/2025
============================================================================
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    if(!fork()){
        setsid();
        chdir("/");
        umask(0);
            while(1){
                sleep(4);
                printf("Child PID: %d\n", getpid());
                printf("Daemon Process is running...\n");
            }
    }
    else    
        exit(0);
}

/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P30$ ./a.out
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P30$ Child PID: 9599
Daemon Process is running...
Child PID: 9599
Daemon Process is running...
Child PID: 9599

In another terminal kill 9599 to stop
============================================================================
*/