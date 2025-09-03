/*
============================================================================
Name : 21.c
Author : Aayank Singhai (MT2025001)
Description : Write a program, call fork and print the parent and child process id.
Date: 28/08/2025
============================================================================
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h> 

int main() {

    pid_t pid;
    pid = fork();
    if (pid == 0)
        printf("Child process: PID = %d, Parent process: PID = %d\n", getpid(), getppid()); //exec by child process
    else 
        printf("Parent process: PID = %d, Child process: PID = %d\n", getpid(), pid); //exec by parent process
    return 0;
}


/*
============================================================================
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P21$ cc 21.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P21$ ./a.out
Parent process: PID = 12902, Child process: PID = 12903
Child process: PID = 12903, Parent process: PID = 12902
============================================================================
*/