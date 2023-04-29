#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 26
#define N 1000

int main()
{
    char *s = malloc(N * sizeof(char));
    scanf("%s", s);

    char *a = malloc(N * sizeof(char));
    scanf("%s", a);

    if (strlen(s) != strlen(a))
    {
        printf("NOT POSSIBLE\n");
        return 0;
    }

    int idx[M][N];
    int cnt[M];
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        int ch = s[i] - 'a';
        idx[ch][cnt[ch]] = i + 1;
        cnt[ch]++;
    }
    int ans[len];
    int ptr[M];
    for (int i = 0; i < len; ++i)
    {
        int ch = a[i] - 'a';
        if (ptr[ch] == cnt[ch])
        {
            printf("NOT POSSIBLE\n");
            return 0;
        }
        ans[i] = idx[ch][ptr[ch]];
        ptr[ch]++;
    }

    for (int i = 0; i < len; ++i)
        printf("%d ", ans[i]);
    printf("\n");

    free(s);
    free(a);

    return 0;
}