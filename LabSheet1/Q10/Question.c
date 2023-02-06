#include <stdio.h>
#include <string.h>

void main()
{
    FILE *file;
    file = fopen("input.txt", "r");

    char s[1000], a[1000];
    fscanf(file, "%s\n%s", s, a);

    int sChar[26], aChar[26];

    for (int x = 0; x < 26; x++)
    {
        sChar[x] = 0;
        aChar[x] = 0;
    }

    int i = 0;
    while (s[i] != '\0')
    {
        sChar[s[i] - 'a']++;
        i++;
    }

    int k = 0;
    while (a[k] != '\0')
    {
        aChar[a[k] - 'a']++;
        k++;
    }

    int current = 1;
    for (int y = 0; y < 26; y++)
    {
        if (sChar[y] != aChar[y])
        {
            current = 0;
            break;
        }
    }

    if (current == 0)
    {
        printf("NOT POSSIBLE");
    }
    else
    {
        printf("POSSIBLE\n");
        int indices[26];
        for (int x = 0; x < 26; x++)
        {
            indices[x] = 0;
        }
        for (int y = 0; y < k; y++)
        {
            indices[s[y]-'a'] = y + 1;
        }
        for (int y = 0; y < k; y++)
        {
            printf("%d ", indices[a[y]-'a']);
        }
    }
}