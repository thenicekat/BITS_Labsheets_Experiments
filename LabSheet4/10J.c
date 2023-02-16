#include <stdio.h>

#define int long long int

int absolute(int x){
    return x > 0 ? x : -x;
}

void main(){
    FILE* file;
    file = fopen("10J.txt", "r");
    
    int num;
    fscanf(file, "%lld", &num);

    int input[num];
    int totalSum = 0;
    for(int i=0; i<num; i++){
        fscanf(file, "%lld", &input[i]);
        totalSum += input[i];
    }

    int chocolatesPerPerson = totalSum/num;
    int answer = 0;
    for(int i = 0; i<num; i++){
        answer += absolute(input[i]-chocolatesPerPerson);
    }

    printf("%lld", answer);
}