#include <stdio.h>

/*
Problem F: Count Distinct
Difficulty: Easy

Since no two students from different colleges are assigned the 
same number and two students from the same college are assigned 
the same number, it is sufficient to count the number of distinct 
numbers in the array to get the number of participating colleges.

Since the array is sorted, every distinct element will occupy a
continuous range of indices. If we know the leftmost index of an element
then we can binary search for its rightmost index in O(logn). Once we
know the range of one element, we can directly move to the leftmost index
of the next element (it will be (rightmost index of current element)+1).
So this can be solved in O(k * logn) if there are k distinct elements
in the array.
*/

int findRightIndex(int a[], int n, int i)
{
    // Bounds
    // lo will always point to an index <= (rightmost index of a[i])
    int lo = i;
    // hi will always point to an index > (rightmost index of a[i])
    int hi = n;

    // Binary Search
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (a[mid] == a[i])
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int countDistinct(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; ++i) 
    {
        i = findRightIndex(a, n, i);
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int ans = countDistinct(a, n);
    printf("%d\n", ans);

    return 0;
}