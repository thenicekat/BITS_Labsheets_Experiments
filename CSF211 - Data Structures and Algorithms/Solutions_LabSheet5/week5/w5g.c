#include <stdio.h>

/*
Problem G
Difficulty: Medium
Original problem: https://leetcode.com/problems/fair-distribution-of-cookies/

Since the constraints are small, the solution
can be found by bruteforcing. Recursively try
out all the possible distributions to find the
one with minimum unfairness. There are n buckets
and k people, so each of the n buckets can have
k different assignments. Therefore, the total
number of possible distributions is k^n. We can
keep track of the unfairness of a distribution
as we recurse so that we can update the minimum
unfairness in O(1).

Overall time complexity: O(k^n).
*/

void recurse(int *a, int n, int k, int *ans, int cur, int idx, int *dis)
{
    if (idx == n)
    {
        *ans = cur;
        return;
    }
    for (int j = 0; j < k; ++j)
    {
        dis[j] += a[idx];
        int ncur = dis[j] > cur ? dis[j] : cur;
        // Unfairness cannot decrease later on, so don't
        // explore distributions if they already have higher
        // unfairness than the current minimum. Pruning
        // some paths like this can sometimes help your
        // solution pass test cases in online assessments,
        // even if the solution isn't optimal.
        if (ncur < *ans)
            recurse(a, n, k, ans, ncur, idx + 1, dis);
        dis[j] -= a[idx];
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);

    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &(a[i]));

    // Initialize answer to maximum
    // possible unfairness
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[i];

    int dis[k];
    for (int i = 0; i < k; ++i)
        dis[i] = 0;

    recurse(a, n, k, &ans, 0, 0, dis);
    printf("%d\n", ans);

    return 0;
}
