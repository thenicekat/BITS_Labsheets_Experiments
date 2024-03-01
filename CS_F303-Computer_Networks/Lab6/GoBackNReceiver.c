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

#define P1 100
#define P2 20

char a[10];
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
        a[i] = k + 48;
        i--;
        z = z / 10;
    }
    a[g] = '\0';
}

int main()
{
    struct sockaddr_in server, client;
    int n, sock, i, j, c = 1, framesToReceive;

    int s = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = 6500;
    server.sin_addr.s_addr = inet_addr("10.0.0.2");

    bind(s, (struct sockaddr *)&server, sizeof(server));
    listen(s, 1);
    n = sizeof(client);
    sock = accept(s, (struct sockaddr *)&client, &n);

    printf("\nTCP Connection Established.\n");

    unsigned int s1 = (unsigned int)time(NULL);
    srand(s1);
    strcpy(timeout, "Time Out ");

    recv(sock, a, sizeof(a), 0);
    framesToReceive = atoi(a);
    printf("\nThe total number frames yet to come is %d", framesToReceive);

    while (1)
    {
        for (i = 0; i < W; i++)
        {
            recv(sock, a, sizeof(a), 0);
            if (strcmp(a, timeout) == 0)
            {
                break;
            }
        }

        i = 0;
        while (i < W)
        {
            j = rand() % P1;
            if (j <= P2)
            {
                send(sock, timeout, sizeof(timeout), 0);
                break;
            }
            else
            {
                convertIntToStr(c);
                // if current <= frames to send
                if (c <= framesToReceive)
                {
                    if (c == framesToReceive)
                    {
                        printf("\nFrame %d received", c);
                    }
                    printf("\nFrame %s Received ", a);
                    send(sock, a, sizeof(a), 0);
                }
                else
                {
                    break;
                }
                c++;
            }

            if (c > framesToReceive)
            {
                break;
            }
            i++;
        }
    }

    close(sock);
    close(s);

    return 0;
}
