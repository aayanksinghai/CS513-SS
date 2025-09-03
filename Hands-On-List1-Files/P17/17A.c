/*
============================================================================
Name : 17A.c
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
#include <fcntl.h>

int main(){
	int ticketno;
	int file = open("ticket.txt", O_WRONLY);
	printf("Enter the Ticket number you want to store: ");
	scanf("%d", &ticketno);
	write(file, &ticketno, sizeof(ticketno));
	printf("Ticket number %d stored succesfully \n", ticketno);
	close(file);
	return 0;
}





/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P17$ ./17A
Enter the Ticket number you want to store: 2
Ticket number 2 stored succesfully 

============================================================================
*/