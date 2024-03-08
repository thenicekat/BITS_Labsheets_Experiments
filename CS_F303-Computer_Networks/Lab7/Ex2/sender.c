#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081
#define BUFFER_SIZE 1024
#define INITIAL_CWND 2
#define INITIAL_SSTHRESH 8

// TCP State
enum TCPState
{
    SLOW_START,
    CONGESTION_AVOIDANCE,
    TIMEOUT
};

int sock = 0;
int ssthresh = INITIAL_SSTHRESH;
int cwnd = INITIAL_CWND;
enum TCPState state = SLOW_START;

int main()
{
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    const char *message = "Hello from sender";
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Initialize sockaddr structure
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "10.0.0.2", &serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }
    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    // Send data to server
    int transmission = 0;
    while (1)
    {
        if (state == CONGESTION_AVOIDANCE)
        {
            cwnd++; // congestion avoidance
            printf("\nThe current cwnd size is %d", cwnd);
            send(sock, message, strlen(message), 0);
            printf("\nMessage sent to server: %s", message);
            transmission++;
            if (transmission == 5)
            {
                state = TIMEOUT;
            }
        }
        else if (state == SLOW_START)
        {
            // slow start
            printf("\nThe current cwnd size is %d", cwnd);
            for (int i1 = 0; i1 < cwnd; i1++)
            {
                send(sock, message, strlen(message), 0);
                printf("\nMessage sent to server: %s", message);
            }
            cwnd = 2 * cwnd;
            if (cwnd > ssthresh)
            {
                state = CONGESTION_AVOIDANCE;
                cwnd = cwnd / 2;
            }

            transmission++;
            if (transmission == 5)
            {
                state = TIMEOUT;
            }
        }
        else if (state == TIMEOUT)
        {
            ssthresh = cwnd / 2;
            cwnd = INITIAL_CWND;
            state = SLOW_START;
        }
        sleep(1); // Simulate delay between packets
    }
    // Close the socket
    close(sock);
    return 0;
}