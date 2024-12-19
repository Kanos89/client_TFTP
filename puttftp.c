#include "puttftp.h"

void puttftp(char *host, char *file) {
    struct addrinfo hints, *res;
    int sock;

    // Set up hints for getaddrinfo
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    // Resolve server address
    if (getaddrinfo(host, "69", &hints, &res) != 0) {
        perror("Error resolving server address");
        return;
    }

    // Create socket
    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        perror("Error creating socket");
        freeaddrinfo(res);
        return;
    }

    // Simulate file upload
    printf("Connecting to server %s to upload file %s\n", host, file);

    // Close resources
    close(sock);
    freeaddrinfo(res);
}
