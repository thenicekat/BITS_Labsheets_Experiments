#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    int b[n][m];
    b[0][0] = a[0][0];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[i][j] = a[i][j];
            if(j){
                b[i][j] += b[i][j - 1];
            }
            else if(i){
                b[i][j] += b[i - 1][m - 1];
            }
        }
    }

    int ri, ci, rh, ch;
    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    if(ri + rh - 1 >= n || ci + ch - 1 >= m){
        printf("NOT POSSIBLE\n");
        return 0;
    }

    int ans = 0;

    for(int i = ri; i < ri + rh; i++){
        for(int j = ci; j < ci + ch; j++){
            ans += b[i][j];
        }
    }

    printf("%d\n", ans);
    

}