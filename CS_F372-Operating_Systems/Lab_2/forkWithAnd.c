#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if (fork() && fork())
    {
        fork();
        printf("Hello %d\n", getpid());
    }
    printf("BITS %d\n", getpid());
    return 0;
}