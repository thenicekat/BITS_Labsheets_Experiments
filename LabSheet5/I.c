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
        int rightcounter = 1;
        
        if(left == 0){
            leftcounter = 1;
        }else{
            leftcounter = oddIndices[i] - oddIndices[i-1];
        }

        if(right == noOfOdds - 1){
            rightcounter = 1;
        }else{
            rightcounter = oddIndices[i+1] - oddIndices[i];
        }

        answer += (leftcounter * rightcounter);
        printf(" %lld %lld %lld", leftcounter, rightcounter, answer);
    }

    printf("\n%lld", answer);
}