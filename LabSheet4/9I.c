#include <stdio.h>

#define int long long int

int max(int a, int b)
{
    return a > b ? a : b;
}

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

    int number, maxNumber = 0;
    fscanf(file, "%lld", &number);

    // Taking input from user
    int input[number];
    for (int i = 0; i < number; i++)
    {
        fscanf(file, "%lld", &input[i]);
        maxNumber = max(maxNumber, input[i]);
    }

    int answer = 0;
    for(int i=0; i<number; i++){
        int gcdWithoutI = input[i+1];
        for(int j=0; j<number; j++){
            if(j != i) gcdWithoutI = gcd(input[j], gcdWithoutI);
        }
        answer = max(answer, gcdWithoutI);
    }
    printf("%lld", answer);

    // // Counting the number of numbers in the input
    // int countingArray[maxNumber + 1];
    // for (int i = 0; i <= maxNumber; i++)
    // {
    //     countingArray[i] = 0;
    // }
    // for (int i = 0; i < number; i++)
    // {
    //     countingArray[input[i]]++;
    // }

    // // Put only some numbers in the input array
    // int tracker = 0;
    // for (int i = 0; i <= maxNumber; i++)
    // {
    //     for (int k = 0; k < countingArray[i]; k++)
    //     {
    //         input[tracker] = i;
    //         tracker++;
    //     }
    // }

    // // Print only the sorted array
    // for (int i = 0; i < number; i++)
    // {
    //     printf("%lld ", input[i]);
    // }
}