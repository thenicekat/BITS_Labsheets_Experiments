#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int cnt[n];
    for (int i = 0; i < n; ++i)
        cnt[i] = 0;
    int queue[n];
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
        queue[r] = x;
        r++;
        while (l < r && cnt[queue[l]] > 1)
            l++;
        if (l == r)
            printf("-1 ");
        else
            printf("%d ", queue[l]);
    }
    printf("\n");
    

    return 0;
}
/*

*/