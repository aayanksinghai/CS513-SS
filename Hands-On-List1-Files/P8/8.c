/*
============================================================================
Name : 8.c 
Author : Aayank Singhai (MT2025001)
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 24/08/2025
============================================================================
*/

#include <stdio.h> 
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 2048

int main(int argc, char *argv[]) {
    int fd;
    char char_buffer; //used to read one char at a time
    ssize_t bytes_read;

    char line_buffer[MAX_LINE_LENGTH]; // buffer for current line
    int line_index = 0; 

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1; 
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((bytes_read = read(fd, &char_buffer, 1)) > 0) {
        line_buffer[line_index] = char_buffer;
        line_index++;


        if (char_buffer == '\n') {
            write(1, line_buffer, line_index);
            line_index = 0;
        }

        if (line_index >= MAX_LINE_LENGTH) {
            write(1, line_buffer, line_index);
            line_index = 0;
        }
    }
    
    if (line_index > 0) {
        write(1, line_buffer, line_index);
    }

    if (bytes_read == -1) {
        perror("Error reading from file");
    }

    close(fd);

    return 0;
}

/*
============================================================================
OUTPUT
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P8$ cc 8.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P8$ ./a.out file.txt
Hi, I am Aayank and writing a code to take print the text\n
I have just changed my line.

============================================================================
*/