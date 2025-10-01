/*
===========================================================================================================================
Name : 26.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 1st October, 2025
===========================================================================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main(){
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg_buffer message;
    message.msg_type = 1;  // Set message type
    strcpy(message.msg_text, "Hello, World!");

    msgsnd(msgid, &message, sizeof(message.msg_text), 0);

    printf("Message sent: %s\n", message.msg_text);

    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P26$ ./a.out
Message sent: Hello, World!
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          aayanksing 666        100          1           
0x41060b3f 1          aayanksing 666        0            0  

===========================================================================================================================
*/