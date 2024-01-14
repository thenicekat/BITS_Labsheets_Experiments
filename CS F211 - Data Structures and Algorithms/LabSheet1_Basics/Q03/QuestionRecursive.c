#include <stdio.h>
#include <string.h>

int isSubsetSum(int* numbers, int sumNeeded, int n){
    if(sumNeeded == 0){
        return 1;
    }

    if(n == 0){
        return 0;
    }

    if(numbers[n-1] > sumNeeded) return isSubsetSum(numbers, sumNeeded, n-1);

    if(isSubsetSum(numbers, sumNeeded, n-1)) return 1;
    
    if(isSubsetSum(numbers, sumNeeded-numbers[n-1], n-1)){
        printf("%d ", n-1);
        return 1;
    }
}


void main(){
    FILE* file;
    file = fopen("input.txt", "r");

    int n;
    fscanf(file, "%d", &n);

    int input[n];
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &input[i]);
    }

    int sum;
    fscanf(file, "%d", &sum);

    if(!isSubsetSum(input, sum, n)){
        printf("NOT POSSIBLE");
    }
}