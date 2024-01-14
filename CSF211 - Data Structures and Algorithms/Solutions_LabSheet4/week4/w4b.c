#include <stdio.h>
#include <stdlib.h>

/*
Problem B
Difficulty: Medium
Original Problem: https://leetcode.com/problems/h-index/

We sort the input array, sorting is O(nlogn).
Suppose x is a possible score. Then the last x elements of the array
after sorting must be >= x, and the remaining elements must be <= x.
Since the array is sorted we can just check the x-th element from the
end and the one before it to see if these two conditions hold.
Finding possible values of x is O(n).

Overall time complexity is O(nlogn).
*/

void merge(int *a, int l1, int l2, int r2)
{
    int n1 = l2 - l1, n2 = r2 - l2;
    int *a1 = malloc(n1 * sizeof(int));
    int *a2 = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; ++i)
        a1[i] = a[l1 + i];
    for (int i = 0; i < n2; ++i)
        a2[i] = a[l2 + i];
    int i = l1, i1 = 0, i2 = 0;
    while (i1 < n1 && i2 < n2)
    {
        if (a1[i1] < a2[i2])
        {
            a[i] = a1[i1];
            i1++;
        }
        else
        {
            a[i] = a2[i2];
            i2++;
        }
        i++;
    }
    while (i1 < n1)
    {
        a[i] = a1[i1];
        i++, i1++;
    }
    while (i2 < n2)
    {
        a[i] = a2[i2];
        i++, i2++;
    }
    free(a1);
    free(a2);
}

// Sorts [l, r) of array a
void sort(int *a, int l, int r)
{
    if (r - l > 1)
    {
        int m = (l + r) / 2;
        sort(a, l, m);
        sort(a, m, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &(a[i]));

    sort(a, 0, n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = n - i;
        if (a[i] >= x && (i == 0 || a[i - 1] <= x))
            ans = x;
    }

    printf("%d\n", ans);
    free(a);

    return 0;
}