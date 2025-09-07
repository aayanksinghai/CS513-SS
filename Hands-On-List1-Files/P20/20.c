/*
============================================================================
Name : 20.c
Author : Aayank Singhai (MT2025001)
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 28/08/2025
============================================================================
*/



#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	if(argc < 2){
		perror("Enter a new Priority Number for your application: \n");
		return 1;
	}

	int newPriority = atoi(argv[1]);
	int priority = nice(0);

	printf("The Current Priority was %d\n", priority);
	priority = nice(newPriority);
	printf("The New Priority is %d\n", priority);

	return 0;
}



/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P20$ cc 20.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P20$ ./a.out 4
The Current Priority was 0
The New Priority is 4
============================================================================
*/