#include <stdio.h>
#include <Stdlib.h>

typedef struct entry
{
    int start;
    int end;
} Entry;

void mergeLists(Entry** entries, int start, int mid, int end)
{
    // We have a left pointer, right pointer
    // Start pointer to add the elements
    int left = 0;
    int right = 0;
    int tracker = start;

    // Length of the left side and the right side
    int lengthOfEntries1 = mid - start + 1;
    int lengthOfEntries2 = end - mid;

    // We make an array of entries and sort them
    Entry* entries1[mid - start + 1];
    Entry* entries2[end - mid];

    // We store these in temporary places
    for (int i = 0; i < lengthOfEntries1; i++)
        entries1[i] = entries[start + i];

    for (int j = 0; j < lengthOfEntries2; j++)
        entries2[j] = entries[mid + 1 + j];

    while (left < lengthOfEntries1 && right < lengthOfEntries2)
    {
        if (entries1[left]->start <= entries2[right]->start)
        {
            entries[tracker] = entries1[left];
            left++;
            tracker++;
        }
        else if (entries1[left]->start > entries2[right]->start)
        {
            entries[tracker] = entries2[right];
            right++;
            tracker++;
        }
    }

    while (left < lengthOfEntries1)
    {
        entries[tracker] = entries1[left];
        left++;
        tracker++;
    }

    while (right < lengthOfEntries2)
    {
        entries[tracker] = entries2[right];
        right++;
        tracker++;
    }

}

void sortLists(Entry** entries, int start, int end)
{
    // Loop until start > end
    if (start < end)
    {
        // You find the midpoint
        // Sort the left and right separately
        // Then you merge the lists
        // In the merge function you call using start, mid and end
        int mid = (start + end) / 2;
        sortLists(entries, start, mid);
        sortLists(entries, mid + 1, end);
        mergeLists(entries, start, mid, end);
    }
}

void printEntries(Entry** entries, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d %d\n", entries[i]->start, entries[i]->end);
    }
}

void main()
{
    FILE *file;
    file = fopen("1A.txt", "r");

    int num;
    fscanf(file, "%d", &num);

    // We make a struct to track both the number
    // We take input using malloc
    Entry* entries[num];
    for (int i = 0; i < num; i++)
    {
        int a, b;
        fscanf(file, "%d %d", &a, &b);

        Entry* newEntry = (Entry*) malloc(sizeof(Entry));
        newEntry->start = a;
        newEntry->end = b;
        entries[i] = newEntry;
    }

    // We call the sorting function from 0 to end
    sortLists(entries, 0, num-1);

    // We keep track of last entry's end time
    int lastExit = entries[0]->end;
    int answerIndex = 1;

    // We create an array for results
    Entry* answerEntries[num];
    answerEntries[0] = entries[0];

    // We loop and check if the next element's start is less then 
    // Current elements end
    // Then if yes, we replace the end with max of curr element's end and
    // next element's end
    // Same with last exit
    for (int i = 1; i < num; i++)
    {
        if (entries[i]->start <= lastExit)
        {
            answerEntries[answerIndex-1]->end = max(lastExit, entries[i]->end);
            lastExit = max(lastExit, entries[i]->end);
        }
        else
        {
            answerEntries[answerIndex] = entries[i];
            lastExit = max(lastExit, entries[i]->end);
            answerIndex++;
        }
    }

    printf("%d\n", answerIndex);
    printEntries(answerEntries, answerIndex);
}