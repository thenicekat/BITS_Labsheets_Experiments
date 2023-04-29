#include <stdio.h>
#include <stdlib.h>

#define N 33000
#define D 10

void updateCount(int *digits, int num)
{
    while (num)
    {
        digits[num % 10]++;
        num /= 10;
    }
}

void maxPrimeDigit(int a, int b)
{
    // b <= 2^30
    // sqrt(b) <= 2^15 <= 33000 = N
    // Sieve to find primes till N => O(Nloglog(N))
    int *isPrime = malloc(N * sizeof(int));
    isPrime[0] = isPrime[1] = 0;
    // Mark every number >= 2 as prime initially
    for (int i = 2; i < N; ++i)
        isPrime[i] = 1;
    for (int i = 2; i * i < N; ++i)
    {
        if (isPrime[i])
        {
            // If i is a prime, any multiple of i cannot be a prime
            for (int j = 2 * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }

    int n = b - a + 1;
    int *isPrimeAB = malloc(n * sizeof(int));
    // Mark every number between a and b as prime, initially
    for (int i = a; i <= b; ++i)
        isPrimeAB[i - a] = 1;
    // Every non-prime number between a and b will have a divisor
    // that would be <= sqrt(b)
    for (int i = 2; i < N; ++i)
    {
        if (isPrime[i])
        {
            // mn stores the least multiple of i >= a and > i
            int mn = ((a + i - 1) / i) * i;
            if (mn == i)
                mn = 2 * i;
            
            for (int j = mn; j <= b; j += i)
                isPrimeAB[j - a] = 0;
        }
    }
    
    // Stores count for each digit across all primes between a to b
    int digits[D];
    for (int i = 0; i < D; ++i)
        digits[i] = 0;

    for (int i = a; i <= b; ++i)
    {
        if (isPrimeAB[i - a])
            updateCount(digits, i);
    }

    int maxCount = 0, ans = -1;
    for (int i = 0; i < D; ++i)
    {
        if (digits[i] > maxCount)
        {
            maxCount = digits[i];
            ans = i;
        }
    }

    printf("%d %d\n", ans, maxCount);
    
    free(isPrime);
    free(isPrimeAB);
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    maxPrimeDigit(a, b);

    return 0;
}