/*
===========================================================================================================================
Name : 34a.c
Author : Aayank Singhai
Description : Write a program to create a concurrent server.
        a. use fork
        b. use pthread_create
Date: 1st October, 2025
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(){

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *hello = "Hello from server";

    // Create socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Set the address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // Listen for connections
    listen(server_fd, 3) ;

    while (1) {
        // Accept a connection
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

        // Create a new process for each client
        if (fork() == 0) {
            read(new_socket, buffer, 1024);
            printf("Client: %s\n", buffer);
            send(new_socket, hello, strlen(hello), 0);
            close(new_socket);
            exit(0);
        }
    }

    return 0;
}


/*
OUTPUT
===========================================================================================================================

aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P34$ ./34a
Client: Hello This is a message by Aayank


Open another terminal 
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P34$ telnet localhost 8080
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Hello This is a message by Aayank
Hello from serverConnection closed by foreign host.
===========================================================================================================================
*/