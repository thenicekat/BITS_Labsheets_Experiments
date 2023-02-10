#include <stdio.h>
#define int long long

void main(){
    int input;
    scanf("%lld", &input);
    printf("Input is: %lld\n", input);

    int start = 0;
    int end = input;
    int mid;

    while(start + 1 < end){
        mid = (start + end)/2;
        if(mid == input/mid){
            start = mid;
            break;
        }
        else if(mid > input/mid){
            end = mid;
        }else if(mid < input/mid){
            start = mid;
        }
    }

    printf("Output is: %lld", start);
}