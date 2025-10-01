/*
===========================================================================================================================
Name : 31a.c
Author : Aayank Singhai
Description : Write a program to create a semaphore and initialize value to the semaphore.
            a. create a binary semaphore
            b. create a counting semaphore
Date: 1st October, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){

    sem_t *binary_semaphore;

    // Create and initialize the binary semaphore with initial value 1
    binary_semaphore = sem_open("/binary_sem", O_CREAT, 0644, 1);

    if (binary_semaphore == SEM_FAILED) {
        perror("sem_open failed");
        return 1;
    }

    printf("Binary semaphore created and initialized to 1.\n");

    sem_close(binary_semaphore);
    sem_unlink("/binary_sem");

    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P31$ gcc -o 31a 31a.c -pthread
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P31$ gcc -o 31b 31b.c -pthrea
d
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P31$ ls
31a  31a.c  31b  31b.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P31$ ./31a
Binary semaphore created and initialized to 1.
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P31$ ./31b
Counting semaphore created and initialized to 3.

===========================================================================================================================
*/