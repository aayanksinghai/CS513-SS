/*
===========================================================================================================================
Name : 17b.c
Author : Aayank Singhai
Description : Write a program to execute ls -l | wc.
            b. use dup2
Date: 23rd September, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pipe(pipefd);
    
    if (fork() == 0) { // Child process
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to the write end of the pipe
        close(pipefd[0]);
        close(pipefd[1]); // Close duplicate file descriptor
        execlp("ls", "ls", "-l", NULL); // Execute "ls -l"
    } else { 
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to the read end of the pipe
        close(pipefd[1]);
        close(pipefd[0]); // Close duplicate file descriptor
        execlp("wc", "wc", NULL); // Execute "wc"
    }
    
    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P17$ cc 17b.c -o 17b
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P17$ ./17b
      6      47     335
      
===========================================================================================================================
*/