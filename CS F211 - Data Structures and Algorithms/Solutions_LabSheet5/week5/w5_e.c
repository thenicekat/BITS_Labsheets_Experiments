#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return a > b ? a : b;
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    
    int l = 0, r = -1;
    int cnt = 0;
    while(r < n - 1 && cnt < k){
        r++;
        cnt += a[r] == 0;
    }
    while(r < n - 1 && a[r + 1] == 1)
        r++;

    int ans = r - l + 1;

    while(r < n - 1){
        r++;
        while(r < n - 1 && a[r] != 0)
            r++;
        
        while(r < n - 1 && a[r + 1] == 1)
            r++;
        
        while(l < r && a[l] != 0)
            l++;
            
        if(a[l] == 0)
            l++;
        
        ans = max(ans, r - l + 1);
    }

    printf("%d\n", ans);

    return 0;
}