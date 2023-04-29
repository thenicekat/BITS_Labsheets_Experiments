#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

int main(){

    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
    }

    int j = -1;
    
    for(int i = 0; i < n; i++){

        if(a[i] < 0){
            int temp = i;

            while(temp > j + 1){
                swap(&a[temp], &a[temp - 1]);
                temp--;
            }

            j++;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}