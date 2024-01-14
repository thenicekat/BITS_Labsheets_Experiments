#include <stdio.h>

#define int long long int

int max(int a, int b){ return a > b ? a : b; }

int gcd(int a, int b)
{
    if(a == 0) return 0;
    if(b == 0) return a;
    return gcd(b, a%b);
}

void main()
{
    FILE *file;
    file = fopen("5E.txt", "r");

    int a, b;
    fscanf(file, "%lld %lld", &a, &b);

    // In this function we are trying to find the maximum coprime
    // Concept is we keep dividing common numbers
    // Until nothing else is possible
    while(gcd(a, b) != 1){
        a /= gcd(a, b);
    }

    printf("%d", a);
}