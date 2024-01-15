#include <stdio.h>

#define int long long int

void main(){
    FILE* file;
    file = fopen("4D.txt", "r");

    int max;
    fscanf(file, "%lld", &max);

    // We initialize a sieve
    // Note: use max+1 and not max
    int sieve[max+1];

    // Initializing sieve values to 1
    for(int i = 0; i<max; i++) sieve[i] = 1;

    for(int i = 2; i*i <= max; i++){
        // 1 means prime, so if it's 1 we mark all multiples of it to 0
        if(sieve[i] == 1){
            for(int j=2; j*i<max; j++){
                sieve[j*i] = 0;
            }
        }
    }

    // Then we take input and print sieve
    int num;
    fscanf(file, "%lld", &num);

    for(int i=0; i<num; i++){
        int temp;
        fscanf(file, "%lld", &temp);

        int counter = 0;

        for(int i=2; i<=temp; i++){
            if(sieve[i] == 1) counter++;
        }

        printf("%lld ", counter);
    }
}