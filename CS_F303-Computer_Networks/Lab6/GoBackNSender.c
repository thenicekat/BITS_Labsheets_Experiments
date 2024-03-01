#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define W 5

char message[10];
char timeout[10];

void convertIntToStr(int z)
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
        message[i] = k + 48;
        i--;
        z = z / 10;
    }
    message[g] = '\0';
}

int main()
{
    int framesToSend, windowLength, current = 1, i = 0, j, p = 0, e = 0;

    struct sockaddr_in server;
    int s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = 6500;
    server.sin_addr.s_addr = inet_addr("10.0.0.2");

    connect(s, (struct sockaddr *)&server, sizeof(server));

    printf("\nTCP Connection Established.\n");
    printf("\nEnter the number of Frames: ");
    scanf("%d", &framesToSend);

    convertIntToStr(framesToSend);

    // Send the number of frames first
    send(s, message, sizeof(message), 0);
    strcpy(timeout, "Time Out ");

    while (1)
    {
        for (i = 0; i < W; i++)
        {
            convertIntToStr(current);
            send(s, message, sizeof(message), 0);
            if (current <= framesToSend)
            {
                printf("\nFrame %d Sent", current);
                current++;
            }
        }

        i = 0;
        windowLength = W;

        while (i < W)
        {
            recv(s, message, sizeof(message), 0);
            p = atoi(message);
            printf("\n::> Current: %d Window Length: %d, Received: %d", current, windowLength, p);

            if (strcmp(message, timeout) == 0)
            {
                e = current - windowLength;
                if (e < framesToSend)
                {
                    printf("\nTime Out, Resent Frame %d onwards", e);
                }
                break;
            }
            else
            {
                if (p <= framesToSend)
                {
                    printf("\nFrame %s Acknowledged", message);
                    windowLength--;
                }
                else
                {
                    break;
                }
            }

            if (p > framesToSend)
            {
                break;
            }
            i++;
        }

        if (windowLength == 0 && current > framesToSend)
        {
            send(s, timeout, sizeof(timeout), 0);
            break;
        }
        else
        {
            current = current - windowLength;
            windowLength = W;
        }
    }
    close(s);
    return 0;
}
