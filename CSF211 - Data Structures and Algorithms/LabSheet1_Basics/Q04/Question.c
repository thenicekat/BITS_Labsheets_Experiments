#include <stdio.h>
#include <string.h>

void main(){
    FILE* file;
    file = fopen("input.txt", "r");

    int n;
    fscanf(file, "%d\n", &n);

    int a[n];

    int temp;
    for(int i=0; i<n; i++){
        fscanf(file, "%d", &a[i]);
    }

    int initialNegative = 0;
    for(int i=0; i<n; i++){
        if(a[i] < 0){
            int temp = a[i];
            for(int t=i; t>initialNegative; t--){
                a[t] = a[t-1];
            }
            a[initialNegative] = temp;
            initialNegative++;
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}