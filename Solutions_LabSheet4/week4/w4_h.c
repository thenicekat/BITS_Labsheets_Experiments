#include <stdio.h>
#include <stdlib.h>

long long nC2(long long n){
    return n * (n - 1) / 2;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    long long min = 0, max = 0;
    
    max = nC2(n - m + 1);
    min = (n % m) * nC2(n / m + 1) + (m - n % m) * nC2(n / m);

    printf("%lld %lld\n", min, max);

    return 0;
}