#include <stdio.h>
#include <stdlib.h>

/*
Problem E
Difficulty: Medium
Original Problem: https://www.interviewbit.com/problems/largest-coprime-divisor/

We can find all divisors of a in O(sqrt(a)). For each
divisor, we have to find the gcd of the divisor and b.
gcd(x, y) can be found in O(log(min{x, y})) using Euclid's
algorithm. In the worst case, we will have O(sqrt(a))
divisors for a and we will have to check their gcd with
b each time.

Overall time complexity is O(sqrt(a) * log(min{a, b})).
*/

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int ans = 0;
    for (int i = 1; i * i <= a; ++i)
    {
        if (a % i == 0)
        {
            if (gcd(i, b) == 1)
            {
                if (ans < i)
                    ans = i;
            }
            if (gcd(a / i, b) == 1)
            {
                if (ans < a / i)
                    ans = a / i;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}