#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

/*
    int argc - number of command-line arguments
    char const* argv - list of command-line arguments
*/
int main(int argc, char const* argv[]) {

    printf("DEBUG: List of arguments provided\n");
    for (int i = 0; i < argc; i++) {
        printf("DEBUG: argv[%d] contains %s", i, argv[i]);
    }

    //Start client code
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "Hello from client\n";
    char buffer[1024] = { 0 };
    
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <- 0) {
        printf("\nInvalid address / Address not supported \n");
        return -1;
    }

    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(client_fd, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    valread = read(client_fd, buffer, 1024 - 1);
    printf("%s\n", buffer);
    
    close(client_fd);
    return 0;
}