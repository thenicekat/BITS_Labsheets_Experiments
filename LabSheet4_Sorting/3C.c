#include <stdio.h>

#define int long long int

// Minimum Function
int min(int a, int b)
{
    return a < b ? a : b;
}

// Maximum Function
int max(int a, int b)
{
    return a > b ? a : b;
}

// Using box function formula to find number of zeroes
int findNoOfTrailingZeroes(int a)
{
    int fcounter = 0;
    int tcounter = 0;

    int twos = 2;
    while (a / twos > 0)
    {
        int temp = a / twos;
        tcounter += temp;
        twos *= 2;
    }

    int fives = 5;
    while (a / fives > 0)
    {
        int temp = a / fives;
        fcounter += temp;
        fives *= 5;
    }

    return min(fcounter, tcounter);
}

void main()
{
    FILE *file;
    file = fopen("3C.txt", "r");

    int num, maxNumber = 0;
    fscanf(file, "%lld", &num);

    // Take input
    int input[num];
    for (int i = 0; i < num; i++)
    {
        fscanf(file, "%lld", &input[i]);
        maxNumber = max(maxNumber, input[i]);
    }

    // The max of number of zeroes is the max number itself
    int zeroes[maxNumber];

    // So we take an array and initialize it to 0
    for (int i = 0; i < maxNumber; i++)
    {
        zeroes[i] = 0;
    }

    // We increment number of zeroes 
    for(int i = 0; i < num; i++){
        zeroes[findNoOfTrailingZeroes(input[i])]++;
    }

    // If the number of zeroes is same find nC2 for that case
    int answer = 0;
    for(int i=0; i<maxNumber; i++){
        int n = zeroes[i];
        answer += (n*(n-1))/2;
    }
    printf("%lld", answer);
}