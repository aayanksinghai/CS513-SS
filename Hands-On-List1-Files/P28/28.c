/*
============================================================================
Name : 28.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to get maximum and minimum real time priority.
Date: 30/08/2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(){
	int maxPriority,minPriority;
	if((maxPriority = sched_get_priority_max(SCHED_RR)) == -1){
		perror("Error while getting Max Priority\n");
		return 0;
	}
	printf("Max Priority: %d\n",maxPriority);

	if((minPriority = sched_get_priority_min(SCHED_RR)) == -1){
		perror("Error while getting Min Priority\n");
		return 0;
	}
	printf("Min Priority: %d\n",minPriority);
	return 0;
}

/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P28$ ./a.out
Max Priority: 99
Min Priority: 1

============================================================================
*/
