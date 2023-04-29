#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 100000

int checkSatisfied(int have[26], int req[26]){
    for(int i = 0; i < 26; i++){
        if(have[i] < req[i])
            return 0;
    }
    return 1;
}

int main(){
    char s[STR_LEN];
    fgets(s, STR_LEN, stdin);

    int n = strlen(s);

    char w[STR_LEN];
    scanf("%s", w);

    int m = strlen(w);

    int req[26] = {0};
    for(int i = 0; i < m; i++){
        req[w[i] - 'a']++;
    }

    int have[26] = {0};

    int l = 0, r = 0;

    int ans[2] = {0, n};

    while(r < n){

        have[s[r] - 'a']++;

        while(checkSatisfied(have, req)){
            if(ans[1] - ans[0] > r - l){
                ans[1] = r;
                ans[0] = l;
            }
            have[s[l] - 'a']--;
            l++;
        }

        r++;

    }

    if(ans[1] == n){
        printf("NO WINDOW\n");
        return 0;
    }

    // printf("%d %d", ans[0] + 1, ans[1] + 1);
    printf("%d %d\n", ans[0], ans[1]);

    for(int i = ans[0]; i <= ans[1]; i++){
        printf("%c", s[i]);
    }


    // for(int i = ans[0]; i <= ans[1]; i++){
    //     printf("%c", s[i]);
    // }

}