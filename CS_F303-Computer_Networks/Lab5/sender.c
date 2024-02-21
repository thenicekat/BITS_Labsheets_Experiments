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
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[MAX_FRAME_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    // Server address configuration
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("10.0.0.2");
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Number of frames to be sent
    int n;
    printf("Enter the number of frames to be sent: ");
    scanf("%d", &n);

    // Send frames
    for (int i = 0; i < n; i++)
    {
        printf("Sending frame %d\n", i);
        sprintf(buffer, "Frame %d", i);
        write(sockfd, buffer, strlen(buffer));

        // Wait for acknowledgment
        bzero(buffer, MAX_FRAME_SIZE);
        read(sockfd, buffer, MAX_FRAME_SIZE);
        printf("Received acknowledgment from receiver: %s\n", buffer);
    }

    // Send exit signal
    strcpy(buffer, "exit");
    write(sockfd, buffer, strlen(buffer));
    close(sockfd);
    return 0;
}