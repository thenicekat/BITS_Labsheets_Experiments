#include <stdio.h>

#define int long long int

void main()
{
    FILE *file;
    file = fopen("I.txt", "r");

    int inputLength, noOfOddNeeded;
    fscanf(file, "%lld %lld", &inputLength, &noOfOddNeeded);

    int input[inputLength];

    // We count the number of odd numbers
    int noOfOdds = 0;
    for (int i = 0; i < inputLength; i++)
    {
        fscanf(file, "%lld", &input[i]);

        if (input[i] % 2 == 1)
            noOfOdds++;
    }

    // We keep track of odd indices
    int oddIndices[noOfOdds], c = 0;
    for (int i = 0; i < inputLength; i++)
    {
        if (input[i] % 2 == 1)
        {
            oddIndices[c] = i;
            c++;
        }
    }

    int answer = 0;

    for (int i = 0; i < noOfOdds - noOfOddNeeded + 1; i++)
    {
        int left = oddIndices[i];
        int right = oddIndices[i + noOfOddNeeded - 1];

        printf("\n%lld %lld", left, right); 

        int leftcounter = 1;
        while (left - 1 >= 0 && input[left - 1] % 2 != 1)
        {
            leftcounter++;
            left--;
        }

        int rightcounter = 1;
        while (right + 1 < inputLength && input[right + 1] % 2 != 1)
        {
            rightcounter++;
            right++;
        }

        answer += (leftcounter * rightcounter);
        printf(" %lld %lld %lld", leftcounter, rightcounter, answer);
    }

    printf("\n%lld", answer);
}