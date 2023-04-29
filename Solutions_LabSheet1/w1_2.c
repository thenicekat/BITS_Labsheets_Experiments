#include <stdio.h>
#include <stdlib.h>


int checkCol(int n, int m, int a[n][m], int row_a, int col_a, int p, int q, int b[p][q], int col_b){

    if(row_a + p - 1 >= n){
        return 0;
    }

    for(int i = 0; i < q; i++){
        if(a[row_a + i][col_a] != b[i][col_b]){
            return 0;
        }
    }

    return 1;
}

int checkRow(int n, int m, int a[n][m], int row_a, int col_a, int p, int q, int b[p][q], int row_b){
    
    if(col_a + q - 1 >= m){
        return 0;
    }

    for(int j = 0; j < q; j++){
        if(a[row_a][col_a + j] != b[row_b][j]){
            return 0;
        }
    }

    return 1;
}

int checkSubMatrix(int n, int m, int a[n][m], int row, int col, int p, int q, int b[p][q]){

    if(row + p - 1 >= n || col + q - 1 >= m){
        return 0;
    }

    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++){
            if(a[row + i][col + j] != b[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    int p, q;
    scanf("%d %d", &p, &q);

    int b[p][q];
    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++){
            scanf("%d", &b[i][j]);
        }
    }

    int flagSub = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            flagSub = flagSub || checkSubMatrix(n, m, a, i, j, p, q, b);
        }
    }

    if(flagSub){
        printf("YES\n");
        return 0;
    }

    int flagPartial = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int row_b = 0; row_b < p; row_b++){
                flagPartial = flagPartial || checkRow(n, m, a, i, j, p, q, b, row_b);
            }
            for(int col_b = 0; col_b < q; col_b++){
                flagPartial = flagPartial || checkCol(n, m, a, i, j, p, q, b, col_b);
            }
        }
    }

    if(flagPartial){
        printf("PARTIAL\n");
    }
    else{
        printf("NO\n");
    }

}