/*
===========================================================================================================================
Name : 2.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 20th Sept, 2025.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void rsrc_lmt(int resource, const char *resource_name) {

    struct rlimit limit;

    if (getrlimit(resource, &limit) == 0) {
        printf("%s:\n", resource_name);
        printf("  Soft limit: %ld\n", limit.rlim_cur);
        printf("  Hard limit: %ld\n\n", limit.rlim_max);
    } else {
        perror("getrlimit failed");
        exit(EXIT_FAILURE);
    }
}

int main() {

    rsrc_lmt(RLIMIT_CPU, "CPU time limit");
    rsrc_lmt(RLIMIT_FSIZE, "File size limit");
    rsrc_lmt(RLIMIT_STACK, "Stack size limit");
    rsrc_lmt(RLIMIT_NOFILE, "Number of open files limit");
    rsrc_lmt(RLIMIT_NPROC, "Number of processes limit");

    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P2$ cc 2.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P2$ ls
2.c  a.out
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P2$ ./a.out
CPU time limit:
  Soft limit: -1
  Hard limit: -1

File size limit:
  Soft limit: -1
  Hard limit: -1

Stack size limit:
  Soft limit: 8388608
  Hard limit: -1

Number of open files limit:
  Soft limit: 1048576
  Hard limit: 1048576

Number of processes limit:
  Soft limit: 61813
  Hard limit: 61813
===========================================================================================================================
*/
