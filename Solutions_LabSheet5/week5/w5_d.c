#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);

    int a[n+1];
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);

    int pref[n+1];
    pref[0] = 0;
    
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];

    int ans = 0;
    for(int i = k; i <= n; i++){
        if(pref[i] - pref[i - k] >= k * t)
            ans++;
    }
    
    printf("%d", ans);

    return 0;
}