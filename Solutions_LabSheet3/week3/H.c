#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Problem H: Square Root

We do the binary search on the answer. We will set the left to 0 and right to 1e9 and find the mid at every interation
    - If mid * mid > n, then the ans will lie to the left of mid so we set right to mid - 1.
    - Else the ans may be mid or may lie to the right of mid so we set left to mid.

We stop when left = right.
*/

int main(){
    
    long n;
    scanf("%ld", &n);

    long left = 0, right =1e9;

    while(left < right){
        long mid = (left + right + 1) / 2;
        if(mid * mid > n){
            right = mid - 1;
        }
        else{
            left = mid;
        }
    }

    printf("%ld\n", left);

    return 0;
}