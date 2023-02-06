#include <stdio.h>
#include <string.h>

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

    for(int i=0; i<(1<<n); i++){
        int currentSum = 0;
        int temp = i;

        for(int i=n-1; i>=0; i--){
            if(temp & 1) currentSum += input[i];
            temp/=2;
        }

        if(currentSum == sum){
            int temp = i;
            for(int i=n-1; i>=0; i--){
                if(temp & 1) printf("%d ", i);
                temp/=2;
            }
            return;
        }
    }
    printf("NOT POSSIBLE");
}