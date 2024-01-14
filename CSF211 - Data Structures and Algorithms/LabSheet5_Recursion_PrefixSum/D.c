#include <stdio.h>

#define int long long int

void main()
{
    FILE *file;
    file = fopen("D.txt", "r");

    int noOfTestCases;
    fscanf(file, "%lld", &noOfTestCases);

    for (int i = 0; i < noOfTestCases; i++)
    {
        printf("--------Test Case No: %lld----------\n", i);

        int num, teamSize, threshold;
        fscanf(file, "%lld %lld %lld", &num, &teamSize, &threshold);

        // Instead of calculating average everytime we can use a score threshold i.e. we can 
        // use say 3 is the team size and 4 is the threshold
        // We can use 12 as sum threshold directly
        int scoreThreshold = teamSize * threshold;

        // Generate Prefix Sum Array
        int input[num+1];

        // NOTE: We take an extra element to count the first set of 3 numbers
        int sum = 0;
        input[0] = 0;
        for (int i = 1; i < num + 1; i++){
            int temp;
            fscanf(file, "%lld", &temp);
            sum += temp;
            input[i] = sum;
        }

        int counter = 0;
        for(int i=teamSize; i<num+1; i++){
            if(input[i] - input[i-teamSize] >= scoreThreshold){
                counter++;
            }
        }
        printf("%lld", counter);


        printf("\n------------------------------------\n");
    }
}