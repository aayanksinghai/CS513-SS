/*
============================================================================
Name : 25.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 29/08/2025
============================================================================
*/


#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){

	pid_t childA,childB,childC;
	pid_t childTerminated;
	int wait;

	if((childA = fork()) == -1){
		perror("Error while creating child A\n");
		return 0;
	}
	if(childA == 0){
		printf("Child A created !!!\n");
		printf("Putting Child A to sleep for 5 secs\n");
		sleep(5);
		printf("Child A Woke up\n");
		_exit(0);
	}

	if((childB = fork()) == -1){
		perror("Error while creating child B\n");
		return 0;
	}
	if(childB == 0){
		printf("Child B Created\n");
		printf("Putting Child B to sleep for 10 secs\n");
		sleep(10);
		printf("Child B Woke up\n");
		_exit(0);
	}

	if((childC = fork()) == -1){
		perror("Error while creating child C\n");
		return 0;
	}
	if(childC == 0){
		printf("Child C Created !!\n");
		printf("Putting Child C to sleep for 15 secs\n");
		sleep(15);
		printf("Child C Woke up\n");
		_exit(0);
	}

	printf("Parent waiting for Child C\n");
	childTerminated = waitpid(childC, &wait, 0);
	
	if(childTerminated == childC){
		printf("Child C has exited with exit status: %d\n", wait);
	}else{
		perror("Some Error has Occurred\n");
	}
	return 0;
}

/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P25$ ./a.out
Parent waiting for Child C
Child A created !!!
Putting Child A to sleep for 5 secs
Child B Created
Putting Child B to sleep for 10 secs
Child C Created !!
Putting Child C to sleep for 15 secs
Child A Woke up
Child B Woke up
Child C Woke up
Child C has exited with exit status: 0

============================================================================
*/