#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define W 5

char received[10];
char timeout[10];

void integerToString(int z)
{
    int k, i = 0, j, g;
    k = z;
    while (k > 0)
    {
        i++;
        k = k / 10;
    }
    g = i;
    i--;
    while (z > 0)
    {
        k = z % 10;
        received[i] = k + 48;
        i--;
        z = z / 10;
    }
    received[g] = '\0';
}

int main()
{
    int frames, windowLength, current = 1, i = 0, n, p = 0, e = 0;

    int connection = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = 6500;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(connection, (struct sockaddr *)&server, sizeof(server));

    printf("\nTCP Connection Established.\n");
    printf("\nEnter the number of Frames: ");
    scanf("%d", &frames);

    integerToString(frames);
    send(connection, received, sizeof(received), 0);
    strcpy(timeout, "Time Out ");

    while (1)
    {
        // First we sent all the frames in the window W
        for (i = 0; i < W; i++)
        {
            integerToString(current);
            send(connection, received, sizeof(received), 0);
            if (current <= frames)
            {
                printf("\nFrame %d Sent", current);
                current++;
            }
        }

        // We reset all the counters and wait for the acknowledgement
        i = 0;
        windowLength = W;

        while (i < W)
        {
            recv(connection, received, sizeof(received), 0);
            p = atoi(received);

            if (strcmp(received, timeout) == 0)
            {
                e = current - windowLength;
                if (e < frames)
                {
                    printf("\nTime Out, Resent Frame %d onwards", e);
                }
                break;
            }
            else
            {
                if (p <= frames)
                {
                    printf("\nFrame %s Acknowledged", received);
                    windowLength--;
                }
                else
                {
                    break;
                }
            }
            if (p > frames)
            {
                break;
            }
            i++;
        }
        if (windowLength == 0 && current > frames)
        {
            send(connection, timeout, sizeof(timeout), 0);
            break;
        }
        else
        {
            current = current - windowLength;
            windowLength = W;
        }
    }
    close(connection);
    return 0;
}