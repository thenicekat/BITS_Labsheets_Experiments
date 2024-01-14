#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int totalCnt = 0;
char **ans;

void printAllRBS(int n, char *str){
    
    int cnt = 0;
    for(int i = 0; str[i] != 0; i++){
        if(str[i] == '(') cnt++;
        else cnt--;
        if(cnt < 0)
            return;
    }

    if(strlen(str) == n){
        if(cnt == 0){
            ans[totalCnt] = malloc(n+1 * sizeof(str));
            strcpy(ans[totalCnt++], str);
        }
        return;
    }

    int idx = strlen(str);
    
    str[idx] = '(';
    printAllRBS(n, str);

    str[idx] = ')';
    printAllRBS(n, str);

    str[idx] = 0;

    return;

}

int main(){
    int n;
    scanf("%d", &n);
    char *str = calloc(n + 1, sizeof(char));
    ans = calloc((1 << n), sizeof(char *));
    printAllRBS(n, str);

    printf("%d\n", totalCnt);
    for(int i = 0; i < totalCnt; i++){
        printf("%s\n", ans[i]);
    }
}