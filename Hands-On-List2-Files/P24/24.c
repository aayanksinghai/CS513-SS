/*
===========================================================================================================================
Name : 24.c
Author : Aayank Singhai
Description : Write a program to create a message queue and print the key and message queue id.
Date: 1st October, 2025
===========================================================================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok("24.txt", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    
    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);
    
    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P24$ touch 24.txt
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P24$ ./a.out
Key: 1090915135
Message Queue ID: 1

===========================================================================================================================
*/

