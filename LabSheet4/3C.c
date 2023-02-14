#include <stdio.h>

#define int long long int

int min(int a, int b){
    return a < b ? a : b;
}

int findNoOfTrailingZeroes(int a){
    int fcounter = 0;
    int tcounter = 0;

    int twos = 2;
    while(a/twos > 0){
        int temp = a/twos;
        tcounter += temp;
        twos *= 2;
    }  

    int fives = 5;
    while(a/fives > 0){
        int temp = a/fives;
        fcounter += temp;
        fives *= 5;
    }  

    return min(fcounter, tcounter);
}

void main(){
    FILE* file;
    file = fopen("3C.txt", "r");

    int zeroes;
    
    printf("%d", findNoOfTrailingZeroes(1000000));
}