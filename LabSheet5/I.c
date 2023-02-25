#include <stdio.h>

#define int long long int

void main()
{
    FILE *file;
    file = fopen("I.txt", "r");

    int inputLength, noOfOddNeeded;
    fscanf(file, "%lld %lld", &inputLength, &noOfOddNeeded);

    int input[inputLength];
    for (int i = 0; i < inputLength; i++)
        fscanf(file, "%lld", &input[i]);

    int left = 0;
    int right = 0;
    int noOfOddsFound = input[0] % 2 == 1 ? 1 : 0;

    int counter = 0;
    while (left <= right && right < inputLength)
    {
        if (noOfOddNeeded == noOfOddsFound)
        {
            printf("%lld %lld\n", left, right);
            counter++;
            while (right + 1 < inputLength && input[right + 1] % 2 != 1)
            {
                printf("%lld %lld\n", left, right + 1);
                counter++;
                right++;
            }
        }

        if (noOfOddsFound < noOfOddNeeded)
        {
            right++;
            if (input[right] % 2 == 1)
                noOfOddsFound++;
        }
        else
        {
            if (input[left] % 2 == 1)
                noOfOddsFound--;
            left++;
        }
    }

    printf("%lld", counter);
}