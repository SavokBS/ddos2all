#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int isOn = 1;
    while (isOn) {
        char address[20];
        printf("Enter the address to connect to: ");
        scanf("%s", address);
        int port;
        printf("Enter the port to connect to: ");
        scanf("%d", &port);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error creating socket");
            return 1;
        }

        struct sockaddr_in server_address;
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(port);
        if (inet_pton(AF_INET, address, &server_address.sin_addr) <= 0) {
            perror("Error converting address");
            return 1;
        }

        if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
            perror("Error connecting to server");
            return 1;
        }

        printf("Connected to %s:%d\n", address, port);
        close(sockfd);
        isOn = 0;
    }
    return 0;
}
