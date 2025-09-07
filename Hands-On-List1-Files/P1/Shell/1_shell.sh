# Name: Aayank Singhai (MT2025001)

# 1.a Soft link (symlink system call)
ln -s source.txt softLink.txt

# 1.b Hard link (link system call) 
ln source.txt hardLink.txt

# 1.c FIFO (mkfifo Library Function or mknod system call)
mkfifo fifo


#OUTPUT
#aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P1/Shell$ sh 1_shell.sh
#aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List1-Files/P1/Shell$ ls
#1_shell.sh  fifo  hardLink.txt  softLink.txt  source.txt