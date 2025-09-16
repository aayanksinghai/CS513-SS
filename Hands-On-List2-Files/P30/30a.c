/*
============================================================================
Name : 30a.c
Author : Aayank Singhai 
Description : Write a program to create a shared memory.
                a. Write some data to the shared memory
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
    printf("Enter the text to put in the shared memory: ");
    scanf("%[^\n]s", data);

    printf("Written successful\n");
    return(0);
}


/*
OUTPUT 

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P30$ cc 30a.c -o 30a
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P30$ ./30a
Enter text to put in shared memory: Hi My Name is Aayank Singhai 
Write successful

*/