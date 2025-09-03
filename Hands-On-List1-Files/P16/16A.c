/*
============================================================================
Name : 16A.c
Author : Aayank Singhai (MT2025001)
Description : 16. Write a program to perform mandatory locking.
a. Implement write lock ***
b. Implement read lock
Date: 28/08/2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(){

	struct flock fm;
	char s[100];
	int fq = open("16.txt", O_RDWR | O_CREAT, 0666);
	fm.l_type = F_WRLCK;
	fm.l_whence = SEEK_SET;
	fm.l_start = 0;
	fm.l_len = 0;
	fm.l_pid = getpid();
	printf("Before locking the file for writing\n");
	fcntl(fq, F_SETLKW, &fm);
	printf("Write lock acquired successfully....\n");
	printf("Press a key to unlock...\n");
	getchar();
	fm.l_type = F_UNLCK;
	fcntl(fq, F_SETLK, &fm);
	printf("Finish\n");
	return 0;
}

/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P16$ ./a.out 16.txt
Before locking the file for writing
Write lock acquired successfully....
Press a key to unlock...

Finish

In another terminal
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P16$ ./a.out 16.txt
Before locking the file for writing


============================================================================
*/