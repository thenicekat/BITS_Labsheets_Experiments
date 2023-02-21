#include <stdio.h>

#define int long long int

void main()
{
    FILE *file;
    file = fopen("F.txt", "r");

    int n;
    fscanf(file, "%lld", &n);
    int arrayA[n];
    for (int i = 0; i < n; i++)
        fscanf(file, "%lld", &arrayA[i]);

    int m;
    fscanf(file, "%lld", &m);
    int arrayB[m];
    for (int i = 0; i < m; i++)
        fscanf(file, "%lld", &arrayB[i]);

    int arrayC[m*n];
    for(int i=0; i<m*n; i++){
        int x = i/m;
        int y = i%m;
        arrayC[i] = arrayA[x]^arrayB[y];
        printf("%lld ", arrayC[i]);
    }

    int c = 0;
    for(int i = 0; i<m*n; i++){
        c ^= arrayC[i];
    }
    printf("\n");

    printf("%lld", c);
}