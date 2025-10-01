/*
========================================================================================================
Name : 27b.c
Author : Aayank Singhai
Description : Write a program to receive messages from the message queue.
		    a. With 0 as a flag
		    b. with IPC_NOWAIT as a flag
Date: 1st October, 2025.
========================================================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct msg {
    long type;
    char text[50];
};

int main(){

    key_t key = ftok(".", 'A');

    int msqid = msgget(key, IPC_CREAT | 0666);

    struct msg message;
    printf("Enter message type (positive integer): ");
    scanf("%ld", &message.type);
    getchar();

    printf("Enter message text: \n");
    fgets(message.text, sizeof(message.text), stdin);
    if (msgsnd(msqid, &message, sizeof(message.text), 0) == -1) {
        perror("msgsnd");
    } else {
        printf("Message sent successfully.\n");
    }
    return 0;
}


/*
OUTPUT
===========================================================================================================================


===========================================================================================================================
*/