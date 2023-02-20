#include <stdio.h>

#define int long long int

// Maximum function
int max(int a, int b)
{
    return a > b ? a : b;
}

// GCD function
int gcd(int a, int b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void main()
{
    FILE *file;
    file = fopen("9I.txt", "r");

    int numberOfElements, maxNumber = 0;
    fscanf(file, "%lld", &numberOfElements);

    // Taking input from user
    int input[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
    {
        fscanf(file, "%lld", &input[i]);
        maxNumber = max(maxNumber, input[i]);
    }

    // Edge case for numberOfElements = 1
    if (numberOfElements == 1)
        printf("%lld", input[0]);
    else
    {
        int answer = 0;
        for (int i = 0; i < numberOfElements; i++)
        {
            int gcdWithoutI = input[i + 1];
            for (int j = 0; j < numberOfElements; j++)
            {
                if (j != i)
                    gcdWithoutI = gcd(input[j], gcdWithoutI);
            }
            answer = max(answer, gcdWithoutI);
        }
        printf("%lld", answer);
    }
}