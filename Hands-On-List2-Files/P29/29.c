/*
===========================================================================================================================
Name : 29.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to remove the message queue.
Date: 1st October, 2025
===========================================================================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){

    key_t key = ftok("29.txt", 65);

    // Create the message queue if it doesn't exist (IPC_CREAT ensures creation)
    int msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1) {
        printf("Failed to create or access the message queue.\n");
        return 1;
    } else
        printf("Message queue created with ID: %d\n", msgid);

    
    msgctl(msgid, IPC_RMID, NULL); // Now remove the message queue
    printf("Message queue removed.\n");

    return 0;
}



/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P29$ touch 29.txt
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P29$ ./a.out
Message queue created with ID: 4
Message queue removed.
===========================================================================================================================
*/