#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
    }

    int s;
    scanf("%d", &s);

    if(!s){
        printf("POSSIBLE\n");
        return 0;
    }

    long mask = 1ll << n;
    while(mask){

        int sum = 0;

        for(int i = 0; i < n; i++){
            if((mask >> i) & 1){
                sum += a[i];
            }
        }

        if(sum == s){
            break;
        }

        mask--;
    }

    if(!mask){
        printf("NOT POSSIBLE\n");
        return 0;
    }

    printf("POSSIBLE\n");

    for(int i = 0; i < n; i++){
        if((mask >> i) & 1){
            printf("%d ", i);
        }
    }

}