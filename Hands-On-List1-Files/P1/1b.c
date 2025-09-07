/*
============================================================================
Name : 1b.c
Author : Aayank Singhai (MT2025001)
Description : Creating hard link 
Date: 24/08/2025
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    const char *target2 = "/home/aayanksinghai/CS513-SS/Hands-On-List1-Files/P1/hardlink.txt";
    const char *linkPath2 = "/home/aayanksinghai/CS513-SS/Hands-On-List1-Files/P1/HardLink";
    int b =  link(target2,linkPath2); //creating hard link
    if(b == -1){
        perror("hard link failed\n");
        exit(1);
    }
    printf("Sucessfully hard link created\n");

    return 0;
}

/*
============================================================================
Output:

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P1$ cc 1b.c -o 1b
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P1$ ls
1a  1a.c  1b  1b.c  1c.c  hardlink.txt  SoftLink  softlink.txt
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P1$ ./1b
Sucessfully hard link created
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P1$ ls
1a  1a.c  1b  1b.c  1c.c  HardLink  hardlink.txt  SoftLink  softlink.txt

============================================================================
*/
