#include <stdio.h>

/*
Problem H
Difficulty: Medium
Original problem: https://leetcode.com/problems/continuous-subarray-sum/

Suppose we have the prefix sum array for the given array.
If the sum of the elements of the subarray [l, r]
is a multiple of k, then (pref_sum[r]-pref_sum[l-1])
will be divisible by k. Equivalently,
pref_sum[r] % k == pref_sum[l-1] % k.

So we can iterate on r = 1... n and count the
number of l such that l <= r, and
pref_sum[r] % k == pref_sum[l-1] % k.
But iterating on all possible values of l for every
r will be O(n), which will make our overall solution
O(n^2).

Notice that we are only concerned with the value of
(pref_sum[i] % k) and not pref_sum[i]. Even though
pref_sum[i] could take values upto 10^6 * 10^9 = 10^15,
(pref_sum[i] % k) will always be < k <= 10^6.
So we can construct an array of size k, and keep track
of how many prefixes of the array had a particular sum
modulo k. Then we can find the number of valid l values
for a given r in O(1). This would bring down the overall
time complexity of our solution to O(n).

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

    int cnt[k];
    for (int i = 0; i < k; ++i)
        cnt[i] = 0;
    cnt[0] = 1;

    int sum = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        sum = (sum + a[i]) % k;
        ans += cnt[sum];
        cnt[sum]++;
    }
    printf("%lld\n", ans);

    return 0;
}