#include <stdio.h>

/*
Problem I
Difficulty: Medium
Original problem: https://leetcode.com/problems/count-number-of-nice-subarrays/

Since we are only concerned with the parity
of the elements, we can take every element
and replace it with the remainder of its
division by 2. Then the problem reduces to
finding non-empty subarrays with sum == k.

This can be solved in a similar way as
Problem H.

Overall time complexity: O(n).
*/

int main()
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);

    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &(a[i]));

    int cnt[n];
    for (int i = 0; i < n; ++i)
        cnt[i] = 0;
    cnt[0] = 1;

    int sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += (a[i] % 2);
        if (sum >= k)
            ans += cnt[sum - k];
        cnt[sum]++;
    }
    printf("%lld\n", ans);

    return 0;
}