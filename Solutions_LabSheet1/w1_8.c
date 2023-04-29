#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

char *reverse(char *s, int n)
{
    char *rev = malloc(n * sizeof(char));
    for (int i = 0; i < n - 1; ++i)
        rev[i] = s[n - 2 - i];
    rev[n - 1] = '\0';
    return rev;
}

int main()
{
    char *line = NULL;
    size_t n = 0;
    ssize_t nread = getline(&line, &n, stdin);

    int cur_size = 0;
    char *cur = malloc(N * sizeof(char));
    int pcount = 0;
    char **palindromes = malloc(N * sizeof(char *));
    for (int i = 0; ; ++i)
    {
        if (line[i] == ' ' || line[i] == '\0')
        {
            cur[cur_size] = '\0';
            cur_size++;
            char *rev = reverse(cur, cur_size);
            printf("%s ", rev);
            if (strlen(rev) > 1 && strcmp(rev, cur) == 0)
            {
                palindromes[pcount] = rev;
                pcount++;
            }
            else
            {
                free(rev);
            }

            cur_size = 0;
        }
        else
        {
            cur[cur_size] = line[i];
            cur_size++;
        }

        if (line[i] == '\0')
            break;
    }
    printf("\n");
    free(cur);
    free(line);

    if (pcount == 0)
    {
        printf("NO PALINDROMES\n");
    }
    else
    {
        for (int i = 0; i < pcount; ++i)
        {
            printf("%s ", palindromes[i]);
            free(palindromes[i]);
        }
        printf("\n");
    }
    free(palindromes);

    return 0;
}