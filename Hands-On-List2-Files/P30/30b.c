/*
============================================================================
Name : 30b.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to create a shared memory.
                b. Attach with O_RDONLY and check whether you are able to overwrite.
Date: 16th Sep, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    key_t key = ftok(".", 'a');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    char *data = shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        return 1;
    }

    printf("Enter the text to be put in the shared memory: ");
    scanf("%[^\n]s", data);

    printf("Written successful: %s\n", data);
    shmdt(data);

    return 0;
}

/*
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P30$ cc 30b.c -o 30b
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P30$ ./30b
Enter the text to be put in the shared memory: 
Written successful: Hi My name is Aayank Singhai 
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P30$ ./30b
Enter the text to be put in the shared memory: I have changed my name from Aayank to ionk
Written successful: I have changed my name from Aayank to ionk

*/