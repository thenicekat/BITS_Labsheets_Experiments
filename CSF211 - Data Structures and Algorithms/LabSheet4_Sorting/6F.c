#include <stdio.h>
#include <stdlib.h>

typedef struct freq
{
    int data;
    int freq;
} Freq;

int max(int a, int b)
{
    return a > b ? a : b;
}

void mergeLists(Freq **frequencies, int start, int mid, int end)
{
    int lengthOfFrequencies1 = mid - start + 1;
    int lengthOfFrequencies2 = end - mid;

    Freq *freq1[lengthOfFrequencies1];
    Freq *freq2[lengthOfFrequencies2];

    for (int i = 0; i < mid - start + 1; i++)
    {
        freq1[i] = frequencies[start + i];
    }
    for (int i = 0; i < end - mid; i++)
    {
        freq2[i] = frequencies[mid + i + 1];
    }

    int left = 0, right = 0, tracker = start;
    while (left < lengthOfFrequencies1 && right < lengthOfFrequencies2)
    {
        if (freq1[left]->freq >= freq2[right]->freq)
        {
            frequencies[tracker] = freq1[left];
            left++;
            tracker++;
        }
        else if (freq1[left]->freq < freq2[right]->freq)
        {
            frequencies[tracker] = freq2[right];
            right++;
            tracker++;
        }
    }

    while (left < lengthOfFrequencies1)
    {
        frequencies[tracker] = freq1[left];
        left++;
        tracker++;
    }

    while (right < lengthOfFrequencies2)
    {
        frequencies[tracker] = freq2[right];
        right++;
        tracker++;
    }
}

void sortFrequencyList(Freq **frequencies, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        sortFrequencyList(frequencies, start, mid);
        sortFrequencyList(frequencies, mid + 1, end);
        mergeLists(frequencies, start, mid, end);
    }
}

void main()
{
    FILE *file;
    file = fopen("6F.txt", "r");

    int number, selected, maxNumber = 0;
    fscanf(file, "%d %d", &number, &selected);

    // Take Input - O(n)
    int input[number];
    for (int i = 0; i < number; i++)
    {
        fscanf(file, "%d", &input[i]);
        maxNumber = max(maxNumber, input[i]);
    }

    // Get Frequencies of each number - O(n)
    int frequency[maxNumber + 1];
    for (int i = 0; i < maxNumber + 1; i++)
    {
        frequency[i] = 0;
    }
    for (int i = 0; i < number; i++)
    {
        frequency[input[i]]++;
    }

    Freq *frequencies[number];
    int counter = 0;
    for (int i = 0; i < maxNumber + 1; i++)
    {
        if (frequency[i] != 0)
        {
            Freq *freq = (Freq *)malloc(sizeof(Freq));
            freq->data = i;
            freq->freq = frequency[i];
            frequencies[counter] = freq;
            counter++;
        }
    }
    number = counter;

    sortFrequencyList(frequencies, 0, number - 1);
    
    for(int i=0; i<selected; i++){
        printf("%d ", frequencies[i]->data);
    }
}