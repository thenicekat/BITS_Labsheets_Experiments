#include <stdio.h>

/*
Problem G: Deductions for Rock
Difficulty: Easy

This problem essentially requires an implementation of the C++ upper_bound() 
method with a slight variation.

We have to find the greatest element in a sorted array that does not exceed 
a given value. The array can be divided into two parts, a non-empty left half
that contains values <= the given limit, and a possibly empty right half 
containing elements > the given limit. We can binary search on the indices 
of the array to find the rightmost index of the left half (they all satisfy the
property a[i] <= k, which is not satisfied by any of the elements of right half).
The value of the rightmost index of the left half is the required answer.
*/

int findMaxDeduction(int a[], int n, int k)
{
    // Bounds
    // lo will always point to an index <= (index of max deduction amount)
    int lo = 0;
    // hi will always point to an index > (index of max deduction amount)
    int hi = n;

    // Binary Search
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (a[mid] <= k)
            lo = mid;
        else
            hi = mid;
    }
    return a[lo];
}

int main()
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int ans = findMaxDeduction(a, n, k);
    printf("%d\n", ans);

    return 0;
}