/*
===========================================================================================================================
Name : server.c
Author : Aayank Singhai (MT2025001)
Description : Write a program to communicate between two machines using socket. (server.c)
Date: 4th Sept, 2025.
===========================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char *message = "Hi! This is a message from server.";

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Bind to the address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    listen(server_fd, 3); // Listen for incoming connections

    printf("Server is listening on port %d...\n", PORT);

    
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen); // Accept a client connection
    
    // Send message to the client
    send(new_socket, message, strlen(message), 0);
    printf("Message sent successfully to client.\n");

    close(new_socket);
    close(server_fd);
    return 0;
}


/*
OUTPUT
===========================================================================================================================
aayanksinghai@aayanksinghai-Vivobook-ASUSLaptop-K3605ZF-K3605ZF:~/CS513-SS/Hands-On-List2-Files/P33$ ./server
Server is listening on port 8080...
Message sent successfully to client.

===========================================================================================================================
*/