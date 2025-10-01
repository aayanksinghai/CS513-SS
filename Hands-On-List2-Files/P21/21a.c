/*
===========================================================================================================================
Name : 21a.c
Author : Aayank Singhai
Description : Write two programs so that both can communicate by FIFO - Use two way communications.
Date: 1st October, 2025
===========================================================================================================================
*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){

    //creating 2 fifo
    mkfifo("myfifo1",0666);
    mkfifo("myfifo2",0666);

    int fd1,fd2;
    char buf[50];

    printf("Process 1 Started \n");

    while(1){
        fd1 = open("myfifo1",O_WRONLY);
        printf("Enter the text:\n");
        fgets(buf,sizeof(buf),stdin);
        write(fd1,buf,strlen(buf)+1);
        close(fd1);

        fd2 = open("myfifo2",O_RDONLY);
        read(fd2,buf,sizeof(buf));
        printf("Process 2: %s",buf);
        close(fd2);
    }

    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P21$ ./21a
Process 1 Started 

Enter the text:
Process 2: Hi I am Aayank
Enter the text:
hi Can you see my message
Process 2: hi Can you see my message

===========================================================================================================================
*/