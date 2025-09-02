/*
============================================================================
Name : 7.c
Author : Aayank Singhai
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 24/08/2025
============================================================================
*/

#include <stdio.h>    
#include <fcntl.h>    // used for file control options like O_RDONLY
#include <unistd.h>   // used for read, write, close

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    
    int source_file, destination_file;
    
    ssize_t bytes_read; //no of bytes read from file
    char buffer[BUFFER_SIZE]; //temp storage to hold data

    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1; 
    }

    source_file = open(argv[1], O_RDONLY); //opening in read only
    if (source_file == -1) {
        perror("Error opening source file");
        return 1;
    }

    destination_file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination_file == -1) {
        perror("Error creating destination file");
        close(source_file); //closing the already opened
        return 1;
    }

    while ((bytes_read = read(source_file, buffer, BUFFER_SIZE)) > 0) {
        if (write(destination_file, buffer, bytes_read) != bytes_read) {
            perror("Error writing to destination file");
            close(source_file);

            close(destination_file);
            return 1;
        }
    }
    close(source_file);
    close(destination_file);

    printf("File copied successfully!\n");

    return 0;

}



/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P7$ echo "Contents written in source file" > source.txt
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P7$ echo "Contents present in destination file" > destination.txt
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P7$ ./a.out source.txt destination.txt
File copied successfully!
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P7$ cat destination.txt
Contents written in source file
============================================================================
*/