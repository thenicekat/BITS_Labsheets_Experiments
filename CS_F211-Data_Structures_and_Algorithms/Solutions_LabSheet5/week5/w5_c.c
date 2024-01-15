#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contains_all(int cnt[], int k){
    for(int i = 0; i < k; i++){
        if(!cnt[i])
            return 0;
    }
    return 1;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    char str[n + 1];
    scanf("%s", str);

    int cnt[k];
    for(int i = 0; i < k; i++) cnt[i] = 0;

    int ans = 0;
    int l = 0, r = -1;
    
    for(l = 0; l < n; l++){
        while(r < n && !contains_all(cnt, k)){
            r++;
            if(r < n)
                cnt[str[r] - 'a']++;
        }
        ans += n - r;
        cnt[str[l] - 'a']--;
    }

    printf("%d\n", ans);

    return 0;

}