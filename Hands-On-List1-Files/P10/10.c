/*
============================================================================
Name : 10.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 25/08/2025
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    off_t offset;
    char buff1[10] = "AAYANKIONK";   // first 10 B
    char buff2[10] = "0202111199";   // next 10  B

    // open file in read-write mode (create if not exists, truncate if exists)
    fd = open("10.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    
    if (write(fd, buff1, 10) != 10) { //10B written
        perror("Write in Buff1");
        close(fd);
        exit(1);
    }

    
    offset = lseek(fd, 10, SEEK_CUR);  //moving by 10B
    if (offset == -1) {
        perror("lseek");
        close(fd);
        exit(1);
    }

    printf("lseek Return Value (new offset): %ld\n", (long)offset);

    // write second 10 bytes
    if (write(fd, buff2, 10) != 10) {
        perror("Write in Buff2");
        close(fd);
        exit(1);
    }

    close(fd);
    return 0;
}



/*
============================================================================
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P10$ cc 10.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P10$ ls
10.c  10.txt  a.out
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P10$ ./a.out
lseek Return Value (new offset): 20

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P10$ od -c 10.txt
0000000   A   A   Y   A   N   K   I   O   N   K  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   0   2   0   2   1   1   1   1   9   9
0000036

============================================================================
*/


