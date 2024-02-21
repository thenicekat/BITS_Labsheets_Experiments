#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_FRAME_SIZE 100

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    int sockfd, newsockfd, clilen;
    int flag = 1;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_FRAME_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    // Server address configuration
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Listen for connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // Accept incoming connection
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    // Receive frames
    while (1)
    {
        bzero(buffer, MAX_FRAME_SIZE);
        read(newsockfd, buffer, MAX_FRAME_SIZE);
        if (strcmp(buffer, "exit") == 0)
            break;

        printf("Received frame: %s\n", buffer);
        // Send acknowledgment
        int n = rand() % 2;
        if (n == 1)
        {
            strcpy(buffer, "ACK");
            write(newsockfd, buffer, strlen(buffer));
        }
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}