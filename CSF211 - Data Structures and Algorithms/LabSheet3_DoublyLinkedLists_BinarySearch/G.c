#include <stdio.h>
#include <limits.h>

int max(int a, int b){
    return a > b ? a : b;
}

void main(){
    FILE* file = fopen("G.txt", "r");

    int noOfElems, maxN;
    fscanf(file, "%d %d", &noOfElems, &maxN);

    int input[noOfElems];

    for(int i = 0; i < noOfElems; i++){
        fscanf(file, "%d", &input[i]);
    }

    int start = 0;
    int end = noOfElems - 1;

    int maxS = INT_MIN;

    while(start <= end){
        int mid = (start + end)/2;

        if(input[mid] < maxN){
            maxS = max(maxS, input[mid]);
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    printf("%d", maxS);
}