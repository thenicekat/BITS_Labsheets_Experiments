// Initially I thought of using stacks but then
// I googled and realized it is using queue
// And using queue you can implement it easily only
// Like we keep printing queue.front until the same number comes, if same number comes,
// we remove the number
// We also need to keep track of these numbers using a frequency array so that they don't become crowded
// on the tail side

// Or it's like we have a queue, and a frequency array, as soon as the frequency crosses 1, we pop
// that element
// something of this sort can be done

#include <stdio.h>

#define int long long int

void main()
{
    FILE *file;
    file = fopen("D.txt", "r");

    // Taking input
    int num;
    fscanf(file, "%lld", &num);

    int array[num];
    for (int i = 0; i < num; i++)
    {
        fscanf(file, "%lld", &array[i]);
    }

    // We make a queue
    int queueTop = 0;
    int queueTracker = -1;
    int queue[num];

    // Make an answer array to keep track of the answer;
    int answer[num];

    // Loop through all the inputs and try to find the non repeating characters
    // We also need to keep track of a frequency array for the same to know if a character repeated or not
    int frequency[num];
    for (int i = 0; i < num; i++)
        frequency[i] = 0;

    for (int i = 0; i < num; i++)
    {
        // First step is to increase frequency of the letter
        frequency[array[i]]++;

        // We add number to queue only if that number has 1 frequency
        if (frequency[array[i]] == 1)
            queue[++queueTracker] = array[i];
    
        // Then we loop until we get a number that has frequency as 1
        while (queueTop <= queueTracker && frequency[queue[queueTop]] > 1)
        {
            queueTop++;
        }

        // Now we need to check from queue that and return that number
        // If queueTop > the current queueTracker, that means there aren't any numbers left
        // we need to return -1
        if (queueTop > queueTracker)
        {
            answer[i] = -1;
        }
        else
            answer[i] = queue[queueTop];
    } 


    // Print the answer
    for (int i = 0; i < num; i++)
    {
        printf("%lld ", answer[i]);
    }
}