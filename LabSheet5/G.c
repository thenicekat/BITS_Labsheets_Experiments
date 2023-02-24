#include <stdio.h>

#define int long long int

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a < b ? b : a;
}

void recursiveMinimumUnfairness(int *buckets, int *answer, int noOfPeople, int index, int* finalAnswer)
{
    if (index == -1)
    {
        int temp = 0;
        for (int i = 0; i < noOfPeople; i++)
            temp = max(answer[i], temp);
        (*finalAnswer) = min((*finalAnswer), temp);
        return;
    }

    for (int i = 0; i < noOfPeople; i++)
    {
        answer[i] += buckets[index];
        recursiveMinimumUnfairness(buckets, answer, noOfPeople, index - 1, finalAnswer);
        answer[i] -= buckets[index];
    }

    return;
}

void main()
{
    FILE *file;
    file = fopen("G.txt", "r");

    int buckets, people;
    fscanf(file, "%lld %lld", &buckets, &people);

    int bucketsInput[buckets];
    for (int i = 0; i < buckets; i++)
        fscanf(file, "%lld", &bucketsInput[i]);

    int answer[people];
    for (int i = 0; i < people; i++)
        answer[i] = 0;

    int finalAnswer = 100000000000;

    recursiveMinimumUnfairness(bucketsInput, answer, people, buckets - 1, &finalAnswer);

    printf("%lld", finalAnswer);
}