#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void handleConnection(int* sock_fd_ptr){
    int sock_fd = *sock_fd_ptr;
    free(sock_fd_ptr);


    printf("Handling connection on %d", sock_fd);
    while(1){
        char buffer[1024];
        strcpy(buffer, "");
        int bytes_read = read(sock_fd, buffer, sizeof(buffer));
        if(bytes_read == 0){
            printf("Closed connection\n");
            close(sock_fd);
            return;
        }
        printf("Read %d bytes from %d: '%s'\n", bytes_read, sock_fd, buffer);
        write(sock_fd, buffer, bytes_read);
    }
    printf("Done with connection %d", sock_fd);
}