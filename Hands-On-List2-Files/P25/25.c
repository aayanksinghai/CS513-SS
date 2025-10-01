/*
===========================================================================================================================
Name : 25.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
            a. access permission
            b. uid, gid
            c. time of last message sent and received
            d. time of last change in the message queue
            d. size of the queue
            f. number of messages in the queue
            g. maximum number of bytes allowed
            h. pid of the msgsnd and msgrcv
Date: 1st October, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main(){

    key_t key = ftok("25.txt", 62);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msqid_ds info;
    msgctl(msgid, IPC_STAT, &info);

    printf("Access Permission: %o\n", info.msg_perm.mode);

    printf("UID: %d\n", info.msg_perm.uid);
    printf("GID: %d\n", info.msg_perm.gid);

    printf("Last msg sent: %s", ctime(&info.msg_stime));
    printf("Last msg received: %s", ctime(&info.msg_rtime));

    printf("Last change: %s", ctime(&info.msg_ctime));

    printf("Size of queue (bytes): %lu\n", info.__msg_cbytes);

    printf("Number of messages: %lu\n", info.msg_qnum);

    printf("Max bytes allowed: %lu\n", info.msg_qbytes);

    printf("PID of last msgsnd: %d\n", info.msg_lspid);
    printf("PID of last msgrcv: %d\n", info.msg_lrpid);

    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P25$ cc 25.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P25$ ./a.out
Access Permission: 666
UID: 1000
GID: 1000
Last msg sent: Thu Jan  1 05:30:00 1970
Last msg received: Thu Jan  1 05:30:00 1970
Last change: Wed Oct  1 17:01:49 2025
Size of queue (bytes): 0
Number of messages: 0
Max bytes allowed: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0
===========================================================================================================================
*/


