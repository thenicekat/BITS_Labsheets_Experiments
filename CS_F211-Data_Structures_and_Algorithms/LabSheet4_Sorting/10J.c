#include <stdio.h>

#define int long long int

int absolute(int x)
{
    return x > 0 ? x : -x;
}

int *mergeSortedLists(int *input, int start, int mid, int end)
{
    int lengthOfFirstHalf = mid - start + 1;
    int lengthOfSecondHalf = end - mid;

    int left[lengthOfFirstHalf];
    int right[lengthOfSecondHalf];

    for (int i = 0; i < lengthOfFirstHalf; i++)
    {
        left[i] = input[start + i];
    }

    for (int i = 0; i < lengthOfSecondHalf; i++)
    {
        right[i] = input[mid + i + 1];
    }

    int leftTracker = 0;
    int rightTracker = 0;
    int tracker = start;

    while (leftTracker < lengthOfFirstHalf && rightTracker < lengthOfSecondHalf)
    {
        if (left[leftTracker] < right[rightTracker])
        {
            input[tracker] = left[leftTracker];
            leftTracker++;
            tracker++;
        }
        else
        {
            input[tracker] = right[rightTracker];
            rightTracker++;
            tracker++;
        }
    }

    while (leftTracker < lengthOfFirstHalf)
    {
        input[tracker] = left[leftTracker];
        leftTracker++;
        tracker++;
    }

    while (rightTracker < lengthOfSecondHalf)
    {
        input[tracker] = right[rightTracker];
        rightTracker++;
        tracker++;
    }
}

void mergeSort(int *input, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(input, start, mid);
        mergeSort(input, mid + 1, end);
        mergeSortedLists(input, start, mid, end);
    }
}

void main()
{
    FILE *file;
    file = fopen("10J.txt", "r");

    int num;
    fscanf(file, "%lld", &num);

    int input[num];
    int totalSum = 0;
    for (int i = 0; i < num; i++)
    {
        fscanf(file, "%lld", &input[i]);
        totalSum += input[i];
    }

    mergeSort(input, 0, num - 1);

    int median = input[num / 2];
    int average = totalSum / num;

    printf("Total Available Chocolates: %lld\n", totalSum);

    int answer = 0;

    if (median * num < totalSum)
    {
            printf("Chocolates Per Person: %lld\n", median) ;   
        for (int i = 0; i < num; i++){
            answer += absolute(input[i] - median);
        }
    }
    else
    {
            printf("Chocolates Per Person: %lld\n", average) ;   
        for (int i = 0; i < num; i++){
            answer += absolute(input[i] - average);
        }
    }

    printf("No of Operations: %lld\n", answer);
}