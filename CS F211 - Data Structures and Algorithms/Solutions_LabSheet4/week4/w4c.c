#include <stdio.h>
#include <stdlib.h>

/*
Problem C
Difficulty: Medium
Original Problem: https://leetcode.com/problems/factorial-trailing-zeroes/

The number of zeros in x! are same as the highest power of 5 in x!.
This is given by the following formula:
floor(x / 5) + floor(x / (5^2)) + floor(x / (5^3)) + ...
The number of terms in this formula will be log5(x).

So, the number of trailing zeros in factorial of i-th element 
of the array can be found in O(log(a[i])).
Number of trailing zeros in the factorials of all the elements 
of the array can be found in O(n * log(max(a[i]))).

We can store the frequency of each count of trailing zeros in 
an array. If there are k elements with p zeros trailing zeros 
in their factorial, we can form kC2 = k*(k-1)/2 good pairs.
p can take values from 0... max(a[i]), so finding number of 
good pairs given the frequency array can be done in O(max(a[i])).

Overall time complexity is O(nlog(max(a[i])) + max(a[i])).
*/

int countTrailingZeros(int x)
{
    int z = 0, num = x / 5;
    while (num)
    {
        z += num;
        num /= 5;
    }
    return z;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    int maxai = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &(a[i]));
        if (maxai < a[i])
            maxai = a[i];
    }

    int *zcnt = calloc(maxai, sizeof(int));
    for (int i = 0; i < n; ++i)
        zcnt[countTrailingZeros(a[i])]++;

    int ans = 0;
    for (int p = 0; p < maxai; ++p)
        ans += zcnt[p] * (zcnt[p] - 1) / 2;
    printf("%d\n", ans);

    free(a);
    free(zcnt);
    return 0;
}