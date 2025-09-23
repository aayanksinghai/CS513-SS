/*
===========================================================================================================================
Name : 17a.c
Author : Aayank Singhai
Description : Write a program to execute ls -l | wc.
            a. use dup
Date: 23rd September, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    int pipefd[2];
    pipe(pipefd);
    
    if (fork() == 0) { 
        dup(pipefd[1]); // Duplicate write end of the pipe to stdout
        close(pipefd[0]); // Close unused read end
        execlp("ls", "ls", "-l", NULL); // Execute "ls -l"
    } else { 
        dup(pipefd[0]); // Duplicate read end of the pipe to stdin
        close(pipefd[1]); // Close unused write end
        execlp("wc", "wc", NULL); // Execute "wc"
    }
    
    return 0;
}



/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P17$ cc 17a.c -o 17a
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P17$ ./17a
total 28
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16176 Sep 23 15:17 17a
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1173 Sep 23 15:15 17a.c
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1292 Sep 23 15:16 17b.c

===========================================================================================================================
*/