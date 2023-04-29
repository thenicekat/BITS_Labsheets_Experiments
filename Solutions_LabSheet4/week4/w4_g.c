#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return a > b ? a : b;
}

int digit_cnt(int n){
    int cnt = 0;
    int val = 1;
    while(n / val){
        val *= 10;
        cnt++;
    }

    return cnt;
}

int pow_10(int i){
    int v = 1;
    while(i--){
        v *= 10;
    }
    return v;
}

int ithdig(int n, int i){
    return (n / pow_10(i)) % 10;
}

void radix_sort(int arr[], int n){

    int max_cnt = 0;
    for(int i = 0; i < n; i++){
        max_cnt = max(max_cnt, digit_cnt(arr[i]));
    }


    for(int i = 0; i < max_cnt; i++){
        int count[10] = {0};
        for(int j = 0; j < n; j++){
            count[ithdig(arr[j], i)]++;
        }
        
        int pos[10] = {0};
        for(int j = 1; j < 10; j++){
            count[j] += count[j - 1];
            pos[j] = count[j - 1];

        }

        int *temp = malloc(n * sizeof(int));

        for(int j = 0; j < n; j++){
            temp[pos[ithdig(arr[j], i)]] = arr[j];
            pos[ithdig(arr[j], i)]++;
        }

        for(int j = 0; j < n; j++){
            arr[j] = temp[j];
            printf("%d ", arr[j]);
        }

        printf("\n");

        free(temp);
    }

    return;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);
    
    radix_sort(arr, n);

    return 0;
}