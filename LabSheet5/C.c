#include <stdio.h>

#define int long long int

void main()
{
    FILE *file;
    file = fopen("C.txt", "r");

    int len, alphabet;
    fscanf(file, "%lld %lld", &len, &alphabet);

    char input[len];
    fscanf(file, "%s", input);
    printf("%s\n", input);

    int alphabetStore[alphabet];

    int start = 0;
    int end = 0;

    // Initializing array to 0
    for (int i = 0; i < alphabet; i++)
    {
        alphabetStore[i] = 0;
    }

    alphabetStore[input[0]-'a']++;
    
    int answer = 0;
    while (end < len)
    {
        // Checking if it satisfies all the letters
        int counter = 0;
        for (int i = 0; i < alphabet; i++)
        {
            if (alphabetStore[i] > 0)
                counter++;
        }

        if (counter == alphabet)
        {
            answer += len - end;
            alphabetStore[input[start] - 'a']--;
            start++;
        }
        else
        {
            end++;
            alphabetStore[input[end] - 'a']++;
        }
    }

    printf("\n%lld", answer);
}