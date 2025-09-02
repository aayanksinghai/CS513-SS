/*
============================================================================
Name : 6.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Close the file when end of file is reached.
Date: 24/08/2025
============================================================================
*/

#include <unistd.h>

int main(){

    char buffer[1024];
    ssize_t bytesRead;

    bytesRead = read(0, buffer, sizeof(buffer)-1);

    if(bytesRead>0){
        buffer[bytesRead]= '\0';
        write(1, buffer, bytesRead);
    }
    return 0;
}




/*
============================================================================
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P6$ ./a.out
Hi I am Aayank Singhai 
Hi I am Aayank Singhai 
============================================================================
*/