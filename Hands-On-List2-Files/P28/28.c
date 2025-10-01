/*
===========================================================================================================================
Name : 28.c
Author : Aayank Singhai
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 1st October, 2025
===========================================================================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){

    key_t key = ftok("28.txt", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msqid_ds info;
    msgctl(msgid, IPC_STAT, &info);

    info.msg_perm.mode = 0644;  //Change permissions to -rw-r--r--

    msgctl(msgid, IPC_SET, &info);  //Apply the changes

    printf("Permissions changed to 0644\n");
    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P28$ ls
28.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P28$ touch 28.txt
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P28$ cc 28.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P28$ ls
28.c  28.txt  a.out
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P28$ ./a.out
Permissions changed to 0644

===========================================================================================================================
*/