#include <stdio.h>
#include <stdlib.h>

/*
Problem J: Captain's Machine

We apply binary search on the answer, we calculate the mid and then find the number of planks of length mid that can be obtained from the given array let it be cnt
    - If cnt < k, then the answer lies to the left of mid, so we set r to mid - 1
    - If cnt >= k, then the answer is either mid or lies to the right of mid, so we set l to mid (Since k planks of length mid can be obtained, we update our answer as well)
*/


int main(){

    int n, k;
    scanf("%d %d", &n, &k);
    
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    
    int l = 0, r = 1e9;
    int ans = 0;
    while(l < r){
        int mid = (l + r + 1) / 2;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            cnt += a[i] / mid;
        }

        if(cnt < k){
            r = mid - 1;
        }
        else{
            l = mid;
            ans = ans > mid ? ans : mid;
        }
    }

    printf("%d", ans);
}