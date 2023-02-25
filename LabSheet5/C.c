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

    int end = alphabet;

    int answer = 0;
    for (int start = 0; start < len - alphabet + 1; start++)
    {
        printf("%lld, %lld ", start, end);
        // Initializing array to 0
        for (int i = 0; i < alphabet; i++)
        {
            alphabetStore[i] = 0;
        }

        // Reading characters in the current window
        for (int i = start; i < end; i++)
        {
            if ((input[i] - 'a') < alphabet)
                alphabetStore[input[i] - 'a']++;
        }

        // Checking if it satisfies all the letters
        int counter = 0;
        for (int i = 0; i < alphabet; i++)
        {
            if (alphabetStore[i] > 0)
                counter++;
        }
        if (counter == alphabet)
        {
            answer += len - end + 1;
        }

        // Incrementing end
        end++;
    }

    printf("%lld", answer);
}