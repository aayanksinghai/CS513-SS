/*
============================================================================
Name : 2.c
Author : Aayank Singhai (MT2025001)
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and 
identify all the process related information in the corresponding proc directory. 
Date: 24/08/2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    while (1) {
        printf("Running process with PID: %d\n", getpid());
        sleep(5);
    }
    return 0;
}

/*
=========================================================================================================
OUTPUT

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P2$ cc 2.c
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P2$ ls
2.c  a.out
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P2$ ./a.out
Running process with PID: 10386
Running process with PID: 10386
Running process with PID: 10386


aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS$ cat /proc/10386/cmdline 
./a.outaayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS$ cat /proc/10386/status
Name:   a.out
Umask:  0002
State:  S (sleeping)
Tgid:   10386
Ngid:   0
Pid:    10386
PPid:   9394
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 24 27 30 46 100 114 1000 
NStgid: 10386
NSpid:  10386
NSpgid: 10386
NSsid:  9394
Kthread:        0
VmPeak:     2684 kB
VmSize:     2684 kB
VmLck:         0 kB
VmPin:         0 kB
VmHWM:      1500 kB
VmRSS:      1500 kB
RssAnon:               0 kB
RssFile:            1500 kB
RssShmem:              0 kB
VmData:      224 kB
VmStk:       136 kB
VmExe:         4 kB
VmLib:      1748 kB
VmPTE:        44 kB
VmSwap:        0 kB
HugetlbPages:          0 kB
CoreDumping:    0
THP_enabled:    1
untag_mask:     0xffffffffffffffff
Threads:        1
SigQ:   0/61813
SigPnd: 0000000000000000
ShdPnd: 0000000000000000
SigBlk: 0000000000000000
SigIgn: 0000000000000000
SigCgt: 0000000000000000
CapInh: 0000000000000000
CapPrm: 0000000000000000
CapEff: 0000000000000000
CapBnd: 000001ffffffffff
CapAmb: 0000000000000000
NoNewPrivs:     0
Seccomp:        0
Seccomp_filters:        0
Speculation_Store_Bypass:       thread vulnerable
SpeculationIndirectBranch:      conditional enabled
Cpus_allowed:   ffff
Cpus_allowed_list:      0-15
Mems_allowed:   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:      0
voluntary_ctxt_switches:        12
nonvoluntary_ctxt_switches:     0
x86_Thread_features:
x86_Thread_features_locked:



=========================================================================================================
*/