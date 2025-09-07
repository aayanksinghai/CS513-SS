/*
============================================================================
Name : 1a.c
Author : Aayank Singhai (MT2025001)
Description : Creating soft link 
Date: 24/08/2025
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    const char *target1 = "/home/aayanksinghai/CS513-SS/Hands-On-List1-Files/P1/softlink.txt";
    const char *linkPath1 = "/home/aayanksinghai/CS513-SS/Hands-On-List1-Files/P1/SoftLink";
    int a = symlink(target1,linkPath1); //creating soft link
    if(a == -1){
        perror("soft link failed\n");
        exit(1);
    }
    printf("Sucessfully Soft link created\n");

    return 0;
}

/*
============================================================================
Output:
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P1$ cc 1a.c -o 1a
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P1$ ./1a
Sucessfully Soft link created
============================================================================
*/


