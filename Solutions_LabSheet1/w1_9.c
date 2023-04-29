#include <stdio.h>

void bubbleUp(int a[], int i, int x)
{
    while (i - 1 >= 0 && a[i - 1] >= x)
    {
        int tmp = a[i - 1];
        a[i - 1] = a[i];
        a[i] = tmp;
        i--;
    }
}

void rearrange(int a[], int n, int x)
{
    int idx = -1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == x)
            idx = i;
        else if (a[i] < x)
        {
            bubbleUp(a, i, x);
            idx++;
        }
    }
    bubbleUp(a, idx, x);
}

int main()
{
    int k;
    scanf("%d", &k);

    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    rearrange(a, n, (k + 1) / 2);

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}