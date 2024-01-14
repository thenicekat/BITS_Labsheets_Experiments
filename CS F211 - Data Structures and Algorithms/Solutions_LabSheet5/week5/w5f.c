#include <stdio.h>

/*
Problem F
Difficulty: Easy
Original problem: https://leetcode.com/problems/bitwise-xor-of-all-pairings/

We have to essentially find
(A[0]^B[0]^A[0]^B[1]^ ... ^A[0]^B[m-1])^
(A[1]^B[0]^A[1]^B[1]^ ... ^A[1]^B[m-1])^
...
(A[n-1]^B[0]^A[n-1]^B[1]^ ... ^A[n-1]^B[m-1])

[Here, ^ = XOR operation]

XORing a number x with itself yields 0, extending
that we can XOR a number with itself an even number
of times to get 0. Consequently we can XOR a number
with itself an odd number of times to get the number
itself.

For all 0 <= i < n, A[i] occurs m times in the expression
For all 0 <= i < m, B[i] occurs n times in the expression

So we can check the parity of n and m and then
iterate through A and/or B accordingly to find
the answer.

Overall time complexity: O(n+m).
*/

int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &(A[i]));
    int m;
    scanf("%d", &m);
    int B[m];
    for (int i = 0; i < m; ++i)
        scanf("%d", &(B[i]));

    int ans = 0;
    if (m % 2 == 1)
    {
        for (int i = 0; i < n; ++i)
            ans ^= A[i];
    }
    if (n % 2 == 1)
    {
        for (int i = 0; i < m; ++i)
            ans ^= B[i];
    }

    printf("%d\n", ans);

    return 0;
}
