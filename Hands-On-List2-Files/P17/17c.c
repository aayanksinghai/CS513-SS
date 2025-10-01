/*
===========================================================================================================================
Name : 17c.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to execute ls -l | wc.
            c. use fcntl
Date: 23rd September, 2025
===========================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    int pipefd[2];
    pipe(pipefd);
    
    if (fork() == 0) { // Child process
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO); // Redirect stdout to the write end of the pipe
        close(pipefd[0]);
        close(pipefd[1]); // Close duplicate file descriptor
        execlp("ls", "ls", "-l", NULL); // Execute "ls -l"
    } else { // Parent process
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO); // Redirect stdin to the read end of the pipe
        close(pipefd[1]);
        close(pipefd[0]); // Close duplicate file descriptor
        execlp("wc", "wc", NULL); // Execute "wc"
    }
    
    return 0;
}

/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P17$ cc 17c.c -o 17c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P17$ ./17c
total 60
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16176 Sep 23 15:17 17a
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1598 Sep 23 15:18 17a.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16176 Sep 23 15:18 17b
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1546 Sep 23 15:18 17b.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16176 Sep 23 15:19 17c
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1354 Sep 23 15:16 17c.c

===========================================================================================================================
*/