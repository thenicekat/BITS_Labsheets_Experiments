#include <stdio.h>

#define int long long int

int max(int a, int b)
{
    return a > b ? a : b;
}

void main()
{
    FILE *file;
    file = fopen("7G.txt", "r");

    int number, maxNumber = 0;
    fscanf(file, "%lld", &number);

    // We take input and store in array
    int input[number];
    for (int i = 0; i < number; i++)
    {
        fscanf(file, "%lld", &input[i]);
        maxNumber = max(maxNumber, input[i]);
    }

    // We need to find the max number of iterations in terms of digits
    int temp = maxNumber;
    int counter = 0;
    while (temp > 0)
    {
        counter++;
        temp /= 10;
    }
    printf("We have %lld iterations\n", counter);

    int tracker = 1;

    // Then we start iterating
    for (int i = 0; i < counter; i++)
    {
        int array[10];
        int answer[number];

        // Initializing array to 0
        for (int i = 0; i < 10; i++)
        {
            array[i] = 0;
        }

        // Make an array for storing last digits
        for (int i = 0; i < number; i++)
        {
            int temp = input[i] / tracker;
            array[temp % 10]++;
        }

        // Make prefix sum array
        int x = 0;
        for (int i = 0; i < 10; i++)
        {
            x += array[i];
            array[i] = x;
        }

        // Sorting the array based on the stable sort version of counting sort
        for (int i = number - 1; i >= 0; i--)
        {
            int temp = input[i] / tracker;
            answer[array[temp % 10] - 1] = input[i];
            array[temp % 10]--;
        }

        for (int i = 0; i < number; i++)
        {
            input[i] = answer[i];
            printf("%lld ", input[i]);
        }

        printf("\n");
        tracker *= 10;
    }
}