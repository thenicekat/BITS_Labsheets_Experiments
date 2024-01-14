#include <stdio.h>
#include <string.h>

void main(){
    FILE* file;
    file = fopen("input.txt", "r");

    int m, n;
    fscanf(file, "%d %d", &m, &n);

    int current = 0;

    int matrix[m][n];
    int matrixUpdated[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    int ri, ci, rh, ch;
    fscanf(file, "%d %d %d %d", &ri, &ci, &rh, &ch);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            current += matrix[i][j];
            matrixUpdated[i][j] = current;
            printf("%d ", current);
        }
        printf("\n");
    }

    int answer = 0;

    if(ri + rh > m || ci + ch > n){
        printf("NOT POSSIBLE");
    }else{
        for(int i=0; i<rh; i++){
            for(int j=0; j<ch; j++){
                answer += matrixUpdated[ri+i][ci+j];
            }
        }
        printf("%d", answer);
    }




}