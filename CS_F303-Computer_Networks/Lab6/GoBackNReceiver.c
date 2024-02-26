#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <arpa/inet.h>

#define W 5
#define P1 50
#define P2 10

char a[10];
char b[10];

void integerToString(int z)
{
    // this converts integer to string
    int k, i = 0, g;
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
        a[i] = k + 48;
        i--;
        z = z / 10;
    }
    a[g] = '\0';
}

int main()
{
    struct sockaddr_in server, client;

    int server_socket, n, accepted_conn, i, current = 1, frames;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = 6500;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(server_socket, (struct sockaddr *)&server, sizeof(server));
    listen(server_socket, 1);

    n = sizeof(client);

    accepted_conn = accept(server_socket, (struct sockaddr *)&client, &n);

    printf("\nTCP Connection Established.\n");
    strcpy(b, "Time Out ");

    recv(accepted_conn, a, sizeof(a), 0);
    frames = atoi(a);

    while (1)
    {
        for (i = 0; i < W; i++)
        {
            recv(accepted_conn, a, sizeof(a), 0);
            if (strcmp(a, b) == 0)
            {
                break;
            }
        }

        i = 0;
        while (i < W)
        {
            // Randomly send timeout
            if (rand() % P1 <= P2)
            {
                send(accepted_conn, b, sizeof(b), 0);
                break;
            }
            else
            {
                // Otherwise, send acknowledgement frame
                integerToString(current);
                if (current <= frames)
                {
                    if (current == frames)
                    {
                        printf("\nFrame %d received", current);
                    }
                    printf("\nFrame %s Received ", a);
                    send(accepted_conn, a, sizeof(a), 0);
                }
                else
                {
                    break;
                }
                current++;
            }
            if (current > frames)
            {
                break;
            }
        }
    }

    close(accepted_conn);
    close(server_socket);
    return 0;
}