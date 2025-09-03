/*
============================================================================
Name : 14.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 27/08/2025
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2){
        printf("Enter the name of the file as the argument\n");
        return 0;
    }
    
    int fd = open(argv[1], O_RDONLY);
    struct stat statbuf;

    fstat(fd, &statbuf);

    if (S_ISREG(statbuf.st_mode))
        write(STDOUT_FILENO, "Regular File\n", 13);
    else if (S_ISDIR(statbuf.st_mode))
        write(STDOUT_FILENO, "Directory File\n", 15);
    else if (S_ISCHR(statbuf.st_mode))
        write(STDOUT_FILENO, "Character File\n", 15);
    else if (S_ISBLK(statbuf.st_mode))
        write(STDOUT_FILENO, "Block File\n", 11);
    else if (S_ISFIFO(statbuf.st_mode))
        write(STDOUT_FILENO, "FIFO File\n", 10);
    else if (S_ISLNK(statbuf.st_mode))
        write(STDOUT_FILENO, "Symbolic Link File\n", 19);
    else if (S_ISSOCK(statbuf.st_mode))
        write(STDOUT_FILENO, "Socket\n", 7);
    else
        write(STDOUT_FILENO, "Error\n", 6);
    return 0;
}



/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P14$ ./acc 14.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P14$ ./a.out
Enter the name of the file as the argument
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P14$ ./a.out 14.txt
Regular File

============================================================================
*/
