#include <stdio.h>
#include <string.h>
#include <math.h>

int isPrime(long long int a){
    if(a <= 1) return 0;

    int prime = 1;
    for(int i=2; i*i<=a; i++){
        if(a%i == 0){
            prime = 0;
        }
    }
    return prime;
}

void main(){
    FILE* file;
    file = fopen("input.txt", "r");

    long long int a, b;
    fscanf(file, "%lld %lld", &a, &b);

    int digits[10];
    for(int k=0; k<10; k++){
        digits[k] = 0;
    }

    for(long long i=a; i<=b; i++){
        if(isPrime(i)){
            // printf("Prime No. %lld\n", i);
            long long int temp = i;
            while(temp > 0){
                digits[temp%10]++;
                temp /= 10;
            }
        }
    }

    long long int digit;
    long long int times = 0;
    for(int i=0; i<10; i++){
        if(times < digits[i]){
            times = digits[i];
            digit = i;
        }
    }

    printf("%lld %lld", digit, times);
}