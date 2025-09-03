/*
============================================================================
Name : 24.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to create an orphan process.
Date: 29/08/2025
============================================================================
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){

	if(fork()){
		printf("Parent process PID: %d\n", getpid());
        printf("Putting Parent process to sleep for 5...\n");
        sleep(5);
		printf("Parent is awake\n");
        printf("Exiting parent!\n");
		_exit(0);
	}else{
		printf("Child process PID: %d\n", getpid());
        printf("Putting Child process to sleep for 10s!\n");
        sleep(10);
        printf("Child is awake now\n");
	}
	return 0;
}



/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P24$ cc 24.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P24$ ls
24.c  a.out
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P24$ ./a.out
Parent process PID: 14527
Putting Parent process to sleep for 5...
Child process PID: 14528
Putting Child process to sleep for 10s!
Parent is awake
Exiting parent!
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P24$ Child is awake now


============================================================================
*/