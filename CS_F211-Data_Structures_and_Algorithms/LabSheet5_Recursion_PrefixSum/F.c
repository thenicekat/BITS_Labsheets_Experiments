#include <stdio.h>

#define int long long int

void main()
{
    FILE *file;
    file = fopen("F.txt", "r");

    int n;
    fscanf(file, "%lld", &n);
    int arrayn[n];
    for (int i = 0; i < n; i++)
        fscanf(file, "%lld", &arrayn[i]);

    int m;
    fscanf(file, "%lld", &m);
    int arraym[m];
    for (int i = 0; i < m; i++)
        fscanf(file, "%lld", &arraym[i]);

    // Here we have two parts to the answer, one which we get from
    // XOR of all the As and one which we get from
    // XOR of all the Bs

    // First we do XOR of all the As
    // Here we also have mn terms
    // Numbers come like 0 m times, 1 m times, 2 m times
    int XOR_a = 0;
    if(m%2 == 0){
        XOR_a = 0;
    }else{
        for(int i = 0; i<n; i++){
            XOR_a ^= arrayn[i];
        }
    }

    // Now XOR of All the Bs
    // Logic is that in B indices we always get 0 1 2 3...m sets
    // So if we find how many sets we get which is n
    // And mod with 2
    int XOR_b = 0;
    if(n%2 == 0){
        XOR_b = 0;
    }else{
        for(int i = 0; i<m; i++){
            XOR_b ^= arraym[i];
        }
    }

    printf("%lld", XOR_a^XOR_b);
}