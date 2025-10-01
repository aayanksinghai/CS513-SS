/*
========================================================================================================
Name : 27a.c
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

struct msg {
    long type;
    char text[50];
};

int main(){

    key_t key = ftok(".", 'A');
    struct msg message;
    int msqid = msgget(key, 0);
   
   int flag, mtype;
    printf("Choose flag:\n1.) 0 (blocking)\n2.) IPC_NOWAIT (non-blocking)\n=> ");
    scanf("%d", &flag);

    printf("Enter message type:\n");
    scanf("%d", &mtype);
    int recv_flag;
    if(flag == 2){
        recv_flag = IPC_NOWAIT;
    }else{
        recv_flag = 0;
    }
    if (msgrcv(msqid, &message, sizeof(message.text), mtype, recv_flag) == -1) {
        perror("msgrcv");
    }else {
        printf("Message: %s\n", message.text);
    }

    return 0;
}



/*
OUTPUT
===========================================================================================================================



===========================================================================================================================
*/