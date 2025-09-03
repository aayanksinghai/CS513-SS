/*
============================================================================
Name : 17B.c
Author : Aayank Singhai (MT2025001)
Description : A> Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. 

B> Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 28/08/2025
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	struct flock fm;
	int ticketno;

	int fq = open("ticket.txt", O_RDWR | O_CREAT);

	if(fq == -1){
		printf("Error: Could not open the file\n");
	}
	else{
		read(fq, &ticketno, sizeof(ticketno));
		fm.l_type = F_WRLCK;
		fm.l_whence = SEEK_SET;
		fm.l_start = 0;
		fm.l_len = 0;
		fm.l_pid = getpid();

		printf("Before entering the critical section...\n");
		fcntl(fq, F_SETLKW, &fm);
		printf("Inside the critical section...\n");
        printf("Previous ticket number: %d\n", ticketno);
		ticketno++;
		printf("Current ticket number: %d\n", ticketno);

		lseek(fq, 0, SEEK_SET);
		write(fq, &ticketno, sizeof(ticketno));
		printf("Press any key to unlock and exit");
		getchar();

		fm.l_type = F_UNLCK;
		fcntl(fq, F_SETLK, &fm);
		close(fq);
		printf("Completed!!!\n");
	}
	return 0;
}






/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P17$ ./17B
Before entering the critical section...
Inside the critical section...
Previous ticket number: 3
Current ticket number: 4
Press any key to unlock and exit
Completed!!!
============================================================================
*/