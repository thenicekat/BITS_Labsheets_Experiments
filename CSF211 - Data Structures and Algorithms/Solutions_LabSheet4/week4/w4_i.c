#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int gcd(int a, int b){
    if(a < b)
        swap(&a, &b);
    
    if(b == 0)
        return a;
    
    return gcd(b, a % b);
}

int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n + 1];
    for(int i = 1; i <= n; i++){
        scanf("%d", arr + i);
    }

    int pref_gcd[n + 2], suff_gcd[n + 2];

    pref_gcd[0] = suff_gcd[n + 1] = 0;
    
    for(int i = 1; i <= n; i++){
        pref_gcd[i] = gcd(pref_gcd[i - 1], arr[i]);
    }

    for(int i = n; i > 0; i--){
        suff_gcd[i] = gcd(suff_gcd[i + 1], arr[i]);
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        int g = gcd(pref_gcd[i - 1], suff_gcd[i + 1]);
        if(g > ans){
            ans = g;
        }
    }

    printf("%d", ans);

    return 0;
}
