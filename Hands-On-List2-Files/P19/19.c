/*
===========================================================================================================================
Name : 19.c
Author : Aayank Singhai (MT2025001)
Description : Create a FIFO file by
                i. mknod command
                ii. mkfifo command
                iii. Use strace command to find out, which command (mknod or mkfifo) is better.
                iv. mknod system call
                v. mkfifo library function
Date: 1st October, 2025
===========================================================================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

    char name[50];
    printf("Enter the name of fifo file: ");
    scanf("%s", name);

    int ch;
    printf("Choose an option:\n1.) mknod system call\n2.) mkfifo system call\n=> ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Using mknod .\n");
        mknod(name, __S_IFIFO | 0744, 0);
        printf("FIFO file created using mknod\n");
        break;
    case 2:
        printf("Using mkfifo .\n");
        mkfifo(name, 0744);
        printf("FIFO file created using mkfifo\n");
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P19$ ./
a.out
Enter the name of fifo file: FirstFIFO
Choose an option:
1.) mknod system call
2.) mkfifo system call
=> 1
Using mknod .
FIFO file created using mknod
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P19$ ls -l
total 20
-rw-rw-r-- 1 aayanksinghai aayanksinghai  1308 Oct  1 15:51 19.c
-rwxrwxr-x 1 aayanksinghai aayanksinghai 16184 Oct  1 15:51 a.out
prwxr--r-- 1 aayanksinghai aayanksinghai     0 Oct  1 15:52 FirstFIFO
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P19$ ./a.out
Enter the name of fifo file: SecondFIFO
Choose an option:
1.) mknod system call
2.) mkfifo system call
=> 2
Using mkfifo .
FIFO file created using mkfifo

  
===========================================================================================================================
*/