/*
===========================================================================================================================
Name : 12.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 21st September, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) { //Child process enters
        printf("Child process (PID: %d), killing parent (PID: %d)\n", getpid(), getppid());
        kill(getppid(), SIGKILL); 
        sleep(2);  // Sleep to become an orphan
        printf("Child process (PID: %d) is now orphan, adopted by init (PID: %d)\n", getpid(), getppid());
    } else {  // Parent process enters
        sleep(10);  // Give some time before parent terminates (if not killed)
    }

    return 0;
}



/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P12$ cc 12.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P12$ ./a.out
Child process (PID: 15911), killing parent (PID: 15910)
Killed
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P12$ Child process (PID: 15911) is now orphan, adopted by init (PID: 2020)

===========================================================================================================================
*/