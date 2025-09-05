/*
============================================================================
Name : a.out.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30/08/2025
============================================================================
*/


#include <stdio.h>

int main(int argc, char *argv[]) {
    
    printf("Hello, My name is %s!\n", argv[1]);
    return 0;
}



/*
============================================================================
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P26$ cc 26.c -o output
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P26$ cc a.out.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P26$ ls
26.c  a.out  a.out.c  output
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P26$ ./output
Hello, My name is Aayank Singhai (MT2025001)!

============================================================================
*/
