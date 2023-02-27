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
        // Then we keep track of where odd numbers are there
        if (input[i] % 2 == 1)
        {
            oddIndices[c] = i;
            // c is used to change the indices of the array of oddIndices
            c++;
        }
    }

    // Empty array to keep track of answer
    int answer = 0;

    // Array to loop through all the odd indices
    for (int i = 0; i < noOfOdds - noOfOddNeeded + 1; i++)
    {
        // left is used to track the first index
        int left = oddIndices[i];
        // right is used to track the second index
        int right = oddIndices[i + noOfOddNeeded - 1];
        printf("\n%lld %lld", left, right); 

        // These counters are used to calculate how many steps we can take on left and right
        int leftcounter = 1;
        int rightcounter = 1;
        
        // If i = 0, that means there's no odd number before this
        // So left counter = the index of the first odd number + 1
        if(i == 0){
            leftcounter = oddIndices[i] + 1;
        }else{
            leftcounter = oddIndices[i] - oddIndices[i-1];
        }

        // If i + noOfOddNeeded - 1 which is basically the second index
        // If this is equal to noOfOdds - 1, that would mean there's no element after this that is odd
        // So we add inputlength - that index
        if(i + noOfOddNeeded - 1 == noOfOdds - 1){
            rightcounter = inputLength - oddIndices[i + noOfOddNeeded - 1];
        }else{
            rightcounter = oddIndices[i + noOfOddNeeded] - oddIndices[i + noOfOddNeeded - 1];
        }

        answer += (leftcounter * rightcounter);
        printf(" %lld %lld %lld", leftcounter, rightcounter, answer);
    }

    printf("\n%lld", answer);
}