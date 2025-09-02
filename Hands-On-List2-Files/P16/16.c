/*
===========================================================================================================================
Name : 16.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 2nd Sept, 2025.
===========================================================================================================================
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void){
    int fd1[2]; 
    int fd2[2]; 
    char buff[100];

    
    pipe(fd1);
    pipe(fd2);

    if(fork()){ //Parent
        close(fd1[0]); //closing unused read end
        close(fd2[1]); //closing unused write end

        char *parentMessage = "I am sending data from parent";
        write(fd1[1], parentMessage, strlen(parentMessage));

        read(fd2[0], buff, sizeof(buff));
        printf("Reading data sent from child: %s\n", buff);        

        close(fd1[1]);
        close(fd2[0]);
         
    }else{ //child
        close(fd1[1]);
        close(fd2[0]);

        read(fd1[0], buff, sizeof(buff));
        printf("Reading data sent from parent: %s\n", buff);


        char *childMessage = "I am sending data from child";
        write(fd2[1], childMessage, strlen(childMessage));

        close(fd1[0]);
        close(fd2[1]);
    }

    return 0;
}



/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P16$ ./a.out
Reading data sent from parent: I am sending data from parent
Reading data sent from child: I am sending data from child
===========================================================================================================================
*/