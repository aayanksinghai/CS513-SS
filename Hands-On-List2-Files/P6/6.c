/*
===========================================================================================================================
Name : 6.c
Author : Aayank Singhai (MT2025001)
Description : Write a simple program to create three threads.
Date: 20th Sept, 2025.
===========================================================================================================================
*/

#include <pthread.h>
#include <stdio.h>

void show_thread(void)
{
    printf("This is a thread\n");
}

int main(){
    pthread_t th1, th2, th3;

    pthread_create(&th1, NULL, (void *)show_thread, NULL);
    pthread_create(&th2, NULL, (void *)show_thread, NULL);
    pthread_create(&th3, NULL, (void *)show_thread, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P6$ cc 6.c -lpthread
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P6$ ./a.out
This is a thread
This is a thread
This is a thread
===========================================================================================================================
*/