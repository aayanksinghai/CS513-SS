/*
============================================================================
Name : a.c
Author : Aayank Singhai
Description : Create a soft link file using the `symlink` system call
Date: 24/08/2025

PENDING
============================================================================
*/

#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Enter Source and Target file name in the argument\n");
        return 0;
    }

    const char *source = argv[1];
    const char *target = argv[2];

    int status = symlink(source, target);
    if(status == -1){
        perror("symlink");
        printf("Error while creating link\n");
    }else{
        printf("Link created successfully\n");
    }
    return 0;
}