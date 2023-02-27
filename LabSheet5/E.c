#include <stdio.h>

#define int long long int

int max(int a, int b){
    return a > b ? a : b;
}

void main(){
    FILE* file;
    file = fopen("E.txt", "r");

    int noOfTestCases;
    fscanf(file, "%lld", &noOfTestCases);

    for(int i=0; i<noOfTestCases; i++){
        printf("--------Test Case No: %lld----------\n", i);
        
        int num, noOfZ;
        fscanf(file, "%lld %lld", &num, &noOfZ);

        int input[num];
        for(int i=0; i<num; i++) fscanf(file, "%lld", &input[i]);

        int start = 0;
        int end = 0;
        int noOfZeroes = input[0] == 0 ? 1 : 0;

        int answer = 0;
        while(end < num && start <= end){
            printf("%lld %lld %lld %lld\n", start, end, noOfZeroes, end - start + 1);
            if(noOfZeroes == noOfZ){
                answer = max(answer, end - start + 1);
            }
            
            if(noOfZeroes <= noOfZ){
                end++;
                if(end == num) break;
                if(input[end] == 0) noOfZeroes++;
            }else{
                if(input[start] == 0) noOfZeroes--;
                start++;
            }
        }
        printf("%lld", answer);

        printf("\n------------------------------------\n");
    }
}