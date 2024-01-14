#include <stdio.h>
 
void main(){
    FILE *file;
    file = fopen("input.txt", "r");
    
    int m1x, m1y;
    fscanf(file, "%d %d", &m1x, &m1y);
    
    int input[m1x][m1y];
    for(int i=0; i<m1x; i++){
        for(int j=0; j<m1y; j++){
            fscanf(file, "%d", &input[i][j]);
        }
    }
    
    int m2x, m2y;
    fscanf(file, "%d %d", &m2x, &m2y);
    
    int submatrix[m2x][m2y];
    for(int i=0; i<m2x; i++){
        for(int j=0; j<m2y; j++){
            fscanf(file, "%d", &submatrix[i][j]);
        }
    }
    
    //Check for rows
    int rowCounter = 0;
    for(int k=0; k<m2x; k++){
        int numberToSearch = submatrix[k][0];
        
        for(int i=0; i<m1x; i++){
            for(int j=0; j<m1y-1; j++){
                if(input[i][j] == numberToSearch){
                    int rowMatch = 1;
                    for(int m=0; m<m2y; m++){
                        if(input[i][j+m] != submatrix[k][m]){
                            rowMatch = 0;
                        }
                    }
                    if(rowMatch == 1) rowCounter++;
                }
            }
        }        
    }
    
    int colCounter = 0;
    for(int k=0; k<m2y; k++){
        int numberToSearch = submatrix[0][k];
        
        for(int i=0; i<m1x; i++){
            for(int j=0; j<m1y-1; j++){
                if(input[i][j] == numberToSearch){
                    int colMatch = 1;
                    for(int m=0; m<m2x; m++){
                        if(input[i+m][j] != submatrix[m][k]){
                            colMatch = 0;
                        }
                    }
                    if(colMatch == 1) colCounter++;
                }
            }
        }        
    }

    printf("%d %d\n", rowCounter, colCounter);
    
    if(rowCounter == m2x && colCounter == m2y){
        printf("YES\n");
        return;
    }
    if(rowCounter == 0 && colCounter == 0){
        printf("NO\n");
        return;
    }
    
    printf("PARTIAL\n");
    return;
   
    
}