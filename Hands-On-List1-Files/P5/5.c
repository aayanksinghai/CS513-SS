/*
===========================================================================================================================
Name : 5.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 24/08/2025
===========================================================================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    while (1) {
        for (int i = 1; i <= 5; ++i) { 
            char filename[10];
            snprintf(filename, sizeof(filename), "file%d", i);
            int fd = open(filename, O_CREAT | O_WRONLY, 0644);
            if (fd < 0) {
                perror("error in opening the file");
                return 1;
            }
            sleep(5);
            close(fd);
        }
    }
    return 0;
}

/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P5$ cc 5.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P5$ ./a.out &
[1] 4850
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P5$ pgrep a.out
4850
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P5$ ls -l /proc/4850/fd
total 0
lrwx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 0 -> /dev/pts/0
lrwx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 1 -> /dev/pts/0
lr-x------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 103 -> /usr/share/code/v8_context_snapshot.bin
lrwx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 2 -> /dev/pts/0
l-wx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 3 -> /home/aayanksinghai/CS513-SS/Hands-On-List1-Files/P5/file2
l-wx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 41 -> /home/aayanksinghai/.config/Code/logs/20250907T223341/ptyhost.log
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P5$ ls -l /proc/4850/fd
total 0
lrwx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 0 -> /dev/pts/0
lrwx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 1 -> /dev/pts/0
lr-x------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 103 -> /usr/share/code/v8_context_snapshot.bin
lrwx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 2 -> /dev/pts/0
l-wx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 3 -> /home/aayanksinghai/CS513-SS/Hands-On-List1-Files/P5/file1
l-wx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 41 -> /home/aayanksinghai/.config/Code/logs/20250907T223341/ptyhost.log
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P5$ ls -l /proc/4850/fd
total 0
lrwx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 0 -> /dev/pts/0
lrwx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 1 -> /dev/pts/0
lr-x------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 103 -> /usr/share/code/v8_context_snapshot.bin
lrwx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 2 -> /dev/pts/0
l-wx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 3 -> /home/aayanksinghai/CS513-SS/Hands-On-List1-Files/P5/file4
l-wx------ 1 aayanksinghai aayanksinghai 64 Aug  24 22:40 41 -> /home/aayanksinghai/.config/Code/logs/20250907T223341/ptyhost.log

============================================================================
*/