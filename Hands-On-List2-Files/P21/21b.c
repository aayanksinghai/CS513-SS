/*
===========================================================================================================================
Name : 21b.c
Author : Aayank Singhai (MT2025001)
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

    int fd1, fd2;
    char buf[50];

    printf("Process 2 Started \n");

    while(1){
        fd1 = open("myfifo1", O_RDONLY);
        read(fd1, buf, sizeof(buf));
        printf("Message from Process 1 :%s\n", buf);
        close(fd1);
        
        fd2 = open("myfifo2", O_WRONLY);
        printf("Enter a Message for Process 1\n");
        fgets(buf, sizeof(buf), stdin);
        write(fd2, buf, strlen(buf)+1);
        close(fd2);

    }

    return 0;
}






/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P21$ ./21b
Process 2 Started 
Message from Process 1 :

Enter a Message for Process 1
Hi I am Aayank
Message from Process 1 :hi Can you see my message

Enter a Message for Process 1

===========================================================================================================================
*/