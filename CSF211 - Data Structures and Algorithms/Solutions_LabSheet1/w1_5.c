#include <stdio.h>
#include <stdlib.h>

#define BLANK 0
#define HBAR -1
#define VBAR -2

void makeSide(int **a, int i, int j, int val, int n, int dir, int maxn)
{
    // printf("i: %d, j: %d, n: %d, dir: %d\n", i, j, n, dir);
    if (dir == 0)
    {
        a[i][j] = HBAR;
        j++;
        for (int k = 0; k < 2 * n - 1; ++k)
        {
            if (k % 2 == 0)
            {
                a[i][j] = val;
                val += 2;
            }
            else
            {
                a[i][j] = VBAR;
            }
            if (k != 2 * n - 2)
                i--;
        }
        makeSide(a, i, j - 1, val, n, dir + 1, maxn);
    }
    else if (dir == 1)
    {
        for (int k = 0; k < 2 * n; ++k)
        {
            if (k % 2 == 1)
            {
                a[i][j] = val;
                val += 2;
            }
            else
            {
                a[i][j] = HBAR;
            }
            if (k != 2 * n - 1)
                j--;
        }
        makeSide(a, i + 1, j, val, n, dir + 1, maxn);
    }
    else if (dir == 2)
    {
        for (int k = 0; k < 2 * n; ++k)
        {
            if (k % 2 == 1)
            {
                a[i][j] = val;
                val += 2;
            }
            else
            {
                a[i][j] = VBAR;
            }
            if (k != 2 * n - 1)
                i++;
        }
        makeSide(a, i, j + 1, val, n, dir + 1, maxn);
    }
    else
    {
        for (int k = 0; k < 2 * n; ++k)
        {
            if (k % 2 == 1)
            {
                a[i][j] = val;
                val += 2;
            }
            else
            {
                a[i][j] = HBAR;
            }
            if (k != 2 * n - 1)
                j++;
        }
        if (n != maxn)
            makeSide(a, i, j + 1, val, n + 2, 0, maxn);
    }
}

void makeSpiral(int n)
{
    if (n == 1)
    {
        printf("2\n");
        return;
    }
    int space = 2 + (n >= 5) + (n >= 13) + (n >= 19);
    // printf("%*s ", space, "―");
    int len = 2 * n - 1;
    int **a = malloc(len * sizeof(int *));
    for (int i = 0; i < len; ++i)
        a[i] = calloc(len, sizeof(int));
    a[n - 1][n - 1] = 2;
    makeSide(a, n - 1, n, 4, 2, 0, n - 1);
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            if (a[i][j] == HBAR)
                printf("%*s", space, "―");
            else if (a[i][j] == VBAR)
                printf("%*s", space, "|");
            else if (a[i][j] == BLANK)
                printf("%*s", space - 1, "");
            else
                printf("%*d", space, a[i][j]);
        }
        printf("\n");
        free(a[i]);
    }
    free(a);
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("Enter odd n\n");
        return 0;
    }

    makeSpiral(n);

    return 0;
}