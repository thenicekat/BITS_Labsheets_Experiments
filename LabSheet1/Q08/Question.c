#include <stdio.h>
#include <string.h>

void main()
{
    FILE *file;
    file = fopen("input.txt", "r");

    char sentence[1000];
    fgets(sentence, 1000, file);
    // printf("%s\n", sentence);

    char palindromes[1000][1000];

    int letterTracker = 0;
    int previousSpace = 0;
    int hasPalindromes = 0;

    while (sentence[letterTracker] != '\0')
    {
        if (sentence[letterTracker] == ' ')
        {
            // This part of the code checks for spaces and prints words in reverse
            for (int i = letterTracker - 1; i >= previousSpace; i--)
            {
                printf("%c", sentence[i]);
            }
            printf(" ");

            // Now to check if the word is a palindrome or not
            int isPalindrome = 1;
            for (int i = previousSpace; i < letterTracker; i++)
            {
                if (sentence[i] != sentence[previousSpace + letterTracker - i - 1])
                    isPalindrome = 0;
            }
            if (isPalindrome)
            {
                for (int i = previousSpace; i < letterTracker; i++)
                {
                    palindromes[hasPalindromes][i - previousSpace] = sentence[i];
                }
                hasPalindromes++;
            }
            previousSpace = letterTracker + 1;
        }
        letterTracker++;
    }

    // For the last word
    for (int i = letterTracker - 1; i >= previousSpace; i--)
    {
        printf("%c", sentence[i]);
    }
    // Now to check if the last word is a palindrome or not
    int isPalindrome = 1;
    for (int i = previousSpace; i < letterTracker; i++)
    {
        if (sentence[i] != sentence[previousSpace + letterTracker - i - 1])
            isPalindrome = 0;
    }
    if (isPalindrome)
    {
        for (int i = previousSpace; i < letterTracker; i++)
        {
            palindromes[hasPalindromes][i - previousSpace] = sentence[i];
        }
        hasPalindromes++;
    }

    if (hasPalindromes == 0)
    {
        printf("\nNO PALINDROMES");
    }
    else
    {
        printf("\n");
        for(int i=0; i<hasPalindromes; i++){
            printf("%s ", palindromes[i]);
        }
    }
}