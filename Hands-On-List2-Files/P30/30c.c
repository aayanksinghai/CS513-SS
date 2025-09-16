/*
============================================================================
Name : 30b.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to create a shared memory.
                c. Detach the shared memory
Date: 16th Sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){

    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    char *data = shmat(shmid, (void *)0, 0);
    printf("Detaching... \n");
    shmdt(data);

    return (0);
}


/*
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P30$ cc 30c.c -o 30c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P30$ ./30c
Detaching... 

'*/