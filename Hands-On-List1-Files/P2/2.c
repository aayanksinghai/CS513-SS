/*
============================================================================
Name : 2.c
Author : Aayank Singhai (MT2025001)
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and 
identify all the process related information in the corresponding proc directory. 
Date: 24/08/2025

PENDING
============================================================================
*/

#include <stdio.h>
#include <stlib.h>
#include <unistd.h>

int main(){
    while(1){
        File *logFile = fopen("2.txt", "a");
        if(logFile){
            fprintf(logFile, "Timestamp: %s", ctime(&(time_t){time(NULL)}));
            system("ls /proc >> 2.txt");
            fprintf(logFile, "---------\n");
            fclose(logFile);
        }
        sleep(10);
    }
    return 0;
}