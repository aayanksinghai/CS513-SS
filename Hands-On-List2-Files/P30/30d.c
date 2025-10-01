/*
============================================================================
Name : 30d.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to create a shared memory.
                d. Remove the shared memory
Date: 16th Sep, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){

    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Delete is unsuccessful\n");
    }
    else
    {
        printf("Deleted successfully\n");
    }

    return (0);
}


/*
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P30$ cc 30d.c -o 30d
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P30$ ./30d
Deleted successfully

*/