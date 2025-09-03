/*
============================================================================
Name : 23.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to create a Zombie state of the running program.
Date: 28/08/2025
============================================================================
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){

	if(fork()){
		printf("Parent process PID: %d\n", getpid());

		printf("Putting the parent to sleep for 10...\n");
        sleep(10);
        printf("Parent is awake now\n");

		wait(NULL);
	}else{
		printf("Child process PID: %d\n", getpid());

		printf("Putting the child to sleep for 5...\n");
        sleep(5);
        printf("Child is awake now\n");

		printf("Child exited\n");
		_exit(0);
	}
	return 0;
}


/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P23$ cc 23.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P23$ ./a.out
Parent process PID: 14199
Putting the parent to sleep for 10...
Child process PID: 14200
Putting the child to sleep for 5...
Child is awake now
Child exited
Parent is awake now

============================================================================
*/