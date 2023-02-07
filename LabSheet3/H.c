#include <stdio.h>
#define int long long

void main(){
    int input;
    scanf("%d", &input);

    int start = 0;
    int end = input;
    int mid;

    while(start + 1 < end){
        mid = (start + end)/2;
        if(mid*mid > input){
            end = mid;
        }else if(mid*mid < input){
            start = mid;
        }
    }

    printf("%d", start);
}