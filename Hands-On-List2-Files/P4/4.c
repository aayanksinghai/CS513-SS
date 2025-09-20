/*
===========================================================================================================================
Name : 4.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 20th Sept, 2025.
===========================================================================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main() {

    clock_t start, end;
    start = clock();

    for (int i = 0; i < 100; i++) {
        getppid();
    }

    end = clock();
    double duration = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The Time taken for 100 getppid system calls: %lf seconds\n", duration);
    return 0;
}

/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P4$ cc 4.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P4$ ./a.out
The Time taken for 100 getppid system calls: 0.000049 seconds
===========================================================================================================================
*/