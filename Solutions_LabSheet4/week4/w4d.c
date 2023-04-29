#include <stdio.h>
#include <stdlib.h>

/*
Problem D
Difficulty: Medium
Original Problem: https://leetcode.com/problems/count-primes/

We can find all primes in [1, n] using Sieve of Eratosthenes
in O(nlog(log(n))). We can then build a prefix sum array for
the isPrime array to answer each query in O(1). Since there
are q queries, all the queries can be answered in O(q).

Overall time complexity is O(nlog(log(n)) + q).
*/

int *sieve(int n)
{
    int *isPrime = malloc((n + 1) * sizeof(int));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= n; ++i)
        isPrime[i] = 1;
    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = 0;
        }
    }
    return isPrime;
}

int main()
{
    int n, q;
    scanf("%d", &n);
    int *pref = sieve(n);
    for (int i = 2; i <= n; ++i)
        pref[i] += pref[i - 1];

    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        int x;
        scanf("%d", &x);
        printf("%d ", pref[x]);
    }
    printf("\n");
    free(pref);

    return 0;
}