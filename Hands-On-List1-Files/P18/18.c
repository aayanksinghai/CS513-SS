/*
============================================================================
Name : 18.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 28/08/2025
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define RECORD_COUNT 3
#define RECORD_SIZE sizeof(struct record)

struct record {
    int recordNumber;
    int someNumber;
};

void initialize_records(int fd) {
    struct record records[RECORD_COUNT] = {
        {1, 0},
        {2, 0},
        {3, 0}
    };
    lseek(fd, 0, SEEK_SET);
    write(fd, records, RECORD_SIZE*RECORD_COUNT);
}

void lock_record(int fd, off_t record_offset) {
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_offset;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error while locking the record");
        _exit(1);
    }
}

void unlock_record(int fd, off_t record_offset) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = record_offset;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error while unlocking the record");
        _exit(1);
    }
}

int main() {
    char *filePath = "18.txt";
    int fd = open(filePath, O_CREAT | O_RDWR, S_IRWXU);
    if (fd == -1) {
        perror("Error while opening the file");
        return 1;
    }
    if (lseek(fd, 0, SEEK_END) == 0) {
        initialize_records(fd);
    }
    for (int i = 0; i < RECORD_COUNT; ++i) {
        off_t record_offset = i * RECORD_SIZE;

        lock_record(fd, record_offset);

        struct record r;
        lseek(fd, record_offset, SEEK_SET);
        read(fd, &r, RECORD_SIZE);
        printf("Record %d: Number = %d\n", r.recordNumber, r.someNumber);

        r.someNumber += 1;
        lseek(fd, record_offset, SEEK_SET);
        write(fd, &r, RECORD_SIZE);

        unlock_record(fd, record_offset);
    }
    return 0;
}


/*
============================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P18$ cc 18.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P18$ ./a.out
Record 1: Number = 0
Record 2: Number = 0
Record 3: Number = 0
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P18$ ./a.out
Record 1: Number = 1
Record 2: Number = 1
Record 3: Number = 1
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P18$ ./a.out
Record 1: Number = 2
Record 2: Number = 2
Record 3: Number = 2
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P18$ ./a.out
Record 1: Number = 3
Record 2: Number = 3
Record 3: Number = 3

============================================================================
*/