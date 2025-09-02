/*
============================================================================
Name : 9.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 25/08/2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

void print_file_info(const char *fileInfo){
    struct stat file_stat; 
    printf("\nFile: %s\n", fileInfo);
    printf("Inode: %ld\n",(long)file_stat.st_ino);
    printf("No. of hard links: %ld\n", (long)file_stat.st_nlink);
    printf("UID: %d\n", file_stat.st_uid);
    printf("GID: %d\n", file_stat.st_gid);
    printf("Size: %ld bytes\n", (long)file_stat.st_size);
    printf("Block Size: %ld bytes\n", (long)file_stat.st_blksize);
    printf("No. of Blocks: %ld\n",(long) file_stat.st_blocks);
    // Use the `ctime` function in `time.h` header to convert the timestamp in epoch to a more human readable form
	printf("Last Access: %s", ctime(&file_stat.st_atime));
	printf("Last Modification: %s", ctime(&file_stat.st_mtime));
	printf("Time of Last change: %s", ctime(&file_stat.st_ctime));
}

int main(){
    const char *fileInfo = "9.txt";
    print_file_info(fileInfo);
    return 0;
}



/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P9$ cc 9.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P9$ ./a.out

File: 9.txt
Inode: 64
No. of hard links: 8
UID: 0
GID: 2048
Size: 32768 bytes
Block Size: 20971520 bytes
No. of Blocks: 20971520
Last Access: Mon Aug 25 15:28:00 2025
Last Modification: Mon Aug 25 15:26:49 2025
Time of Last change: Mon Aug 25 15:26:49 2025
============================================================================
*/

