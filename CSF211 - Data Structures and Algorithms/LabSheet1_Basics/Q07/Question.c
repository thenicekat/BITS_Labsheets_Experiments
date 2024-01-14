#include <stdio.h>
#include <string.h>

void main()
{
    FILE *file;
    file = fopen("input.txt", "r");

    char sentence[1000];
    char input[1000];

    fgets(sentence, 1000, file);
    fgets(input, 1000, file);

    int initialWindowSize = strlen(input);
    int initialStart = 0;
    int initialEnd = initialWindowSize;

    int minWindowSize = 1000;
    int minStart = 0;
    int minEnd = 0;

    int inputAlphabetArray[26];
    for (int i = 0; i < 26; i++)
    {
        inputAlphabetArray[i] = 0;
    }
    for (int i = 0; i < initialWindowSize; i++)
    {
        inputAlphabetArray[input[i] - 'a']++;
    }

    while (initialEnd < strlen(sentence))
    {
        // printf("::> %d %d\n", initialStart, initialEnd);

        int windowAlphabetArray[26];
        for (int i = 0; i < 26; i++)
        {
            windowAlphabetArray[i] = 0;
        }

        for (int i = initialStart; i < initialEnd; i++)
        {
            // Here we check if the character is in the actual input given
            // Otherwise we don't have to compare with it
            if (inputAlphabetArray[sentence[i] - 'a'] != -1)
                windowAlphabetArray[sentence[i] - 'a']++;
        }

        int matches = 1;

        int toShiftStart = 0;
        int toShiftEnd = 0;

        for (int i = 0; i < 26; i++)
        {
            // If they are not equal either there are more or there are less
            if (inputAlphabetArray[i] > windowAlphabetArray[i])
            {

                matches = 0;
                initialEnd++;
            }
        }

        if (matches)
        {
            // printf("Matches\n");
            if (initialEnd - initialStart < minWindowSize)
            {
                minWindowSize = initialEnd - initialStart;
                minStart = initialStart;
                minEnd = initialEnd;
            }
            initialStart++;
        }
    }

    if (minWindowSize != 1000)
    {
        printf("%d %d", minStart, minEnd);
    }
    else
    {
        printf("NO WINDOW");
    }
}