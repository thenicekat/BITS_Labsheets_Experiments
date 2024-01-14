#include <stdio.h>


#define int long long int

// We have a minimum function to find minimum value
int min(int a, int b)
{
    return a > b ? b : a;
}

// We have a maximum function to find maximum value
int max(int a, int b)
{
    return a < b ? b : a;
}

void recursiveMinimumUnfairness(int *buckets, int *answer, int noOfPeople, int index, int* finalAnswer, int currmax)
{
    // If we passed through all the chicken buckets, then we return the minimum maximum
    if (index == -1)
    {
        (*finalAnswer) = min((*finalAnswer), currmax);
        return;
    }

    // For each person, we add chicken, recurse and then remove that chicken and check again
    for (int i = 0; i < noOfPeople; i++)
    {
        answer[i] += buckets[index];
        recursiveMinimumUnfairness(buckets, answer, noOfPeople, index - 1, finalAnswer, max(answer[i], currmax));
        answer[i] -= buckets[index];
    }

    return;
}

void main()
{
    // Taking input
    FILE *file;
    file = fopen("G.txt", "r");

    int buckets, people;
    fscanf(file, "%lld %lld", &buckets, &people);

    // Taking buckets input
    int bucketsInput[buckets];
    for (int i = 0; i < buckets; i++)
        fscanf(file, "%lld", &bucketsInput[i]);

    // We take an empty array with 0s and allot these as people and chicken per person
    int answer[people];
    for (int i = 0; i < people; i++)
        answer[i] = 0;

    // Final Answer to ensure we get minimum answer
    int finalAnswer = 100000000000;

    // Call a recursive function
    recursiveMinimumUnfairness(bucketsInput, answer, people, buckets - 1, &finalAnswer, 0);

    printf("%lld", finalAnswer);
}