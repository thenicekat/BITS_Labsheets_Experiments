#include <stdio.h>

#define int long long int

int max(int a, int b){ return a > b ? a : b; }

int checkCoPrimes(int a, int b)
{
    int status = 1;
    for (int i = 2; i * i < a; i++)
    {
        if (a % i == 0)
        {
            if (b % i == 0)
            {
                status = 0;
            }
        }
    }
    return status;
}

void main()
{
    FILE *file;
    file = fopen("5E.txt", "r");

    int a, b;
    fscanf(file, "%lld %lld", &a, &b);

    printf("%d", checkCoPrimes(285517439, 220253782));
}