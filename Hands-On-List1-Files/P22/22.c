/*
============================================================================
Name : 22.c
Author : Aayank Singhai (MT2025001)
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 28/08/2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>  
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    pid_t pid;
    int fd;
    fd = open("22.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    pid = fork();

    if (pid == -1) {
        perror("Error creating child process");
        close(fd);
        return 1;
    }

    if (pid == 0) {
        //executed by the child process
        const char *child_message = "File written by child process.\n";
        write(fd, child_message, strlen(child_message));
        printf("Child wrote in the file.\n");
        close(fd);
    } 
    else {
        //executed by the parent process
        wait(NULL); //parent wait for the child proc to finish ::: ensuring child write first
        const char *parent_message = "File written by parent process.\n";
        write(fd, parent_message, strlen(parent_message));
        printf("Parent wrote in the file.\n");
        close(fd);
    }
    close(fd);
    return 0;
}



/*
============================================================================
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P22$ cc 22.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P22$ ./a.out
Child wrote in the file.
Parent wrote in the file.

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P22$ cat 22.txt
File written by child process.
File written by parent process.
============================================================================
*/