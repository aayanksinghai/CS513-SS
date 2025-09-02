/*
============================================================================
Name : 11.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 25/08/2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FILENAME "11.txt"
#define ORIGINALBUFFER "This is written using original fd.\n"
#define DUPBUFFER "This is written using dup fd.\n"
#define DUP3BUFFER "This is written using dup2 fd.\n"
#define FCNTLBUFFER "This is written using fcntl fd.\n"

void check_file_update(){
    FILE *file = fopen(FILENAME,"r");
    if(!file){
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    char ch;
    while ((ch = fgetc(file)) != EOF){
        putchar(ch);
    }
    fclose(file);
}

int main(){
    int fd = open(FILENAME, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if(fd < 0){
        perror("open");
        exit(EXIT_FAILURE);
    }
    //using original. fd
    if(write(fd, ORIGINALBUFFER, sizeof(ORIGINALBUFFER) - 1) < 0){
        perror("write");
        exit(EXIT_FAILURE);
    }
    
    /************************** */

    //Duplicate fd using dup
    int fd_dup = dup(fd);
    if(fd_dup < 0){
        perror("dup");
        exit(EXIT_FAILURE);
    }

    //write using the duplicated fd
    if(write(fd_dup, DUPBUFFER, sizeof(DUPBUFFER) - 1) < 0){
        perror("write");
        exit(EXIT_FAILURE);
    }

    /*************************** */

    //Duplicate the fd using dup2
    int fd_dup2 = dup2(fd, 10);
    if(fd_dup2 < 0){
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    //duplicated fd from dup2
    if(write(fd_dup2, DUP3BUFFER, sizeof(DUP3BUFFER) - 1) < 0){
        perror("write");
        exit(EXIT_FAILURE);
    }

    /*************************** */

    //Duplicate the fd using fcntl
    int fd_fcntl = fcntl(fd, F_DUPFD, 0);
    if(fd_fcntl < 0){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    //duplicated fd from fcntl
    if(write(fd_fcntl, FCNTLBUFFER, sizeof(FCNTLBUFFER) - 1) < 0){
        perror("write");
        exit(EXIT_FAILURE);
    }

    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    //checking file
    printf("File Contents '%s':\n",FILENAME);
    check_file_update();
    return 0;

}



/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P11$ cc 11.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P11$ ./a.out
File Contents '11.txt':
This is written using original fd.
This is written using dup fd.
This is written using dup2 fd.
This is written using fcntl fd.

============================================================================
*/
