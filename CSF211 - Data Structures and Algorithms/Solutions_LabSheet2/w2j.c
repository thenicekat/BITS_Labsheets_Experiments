#include <stdio.h>
#include <stdlib.h>

typedef struct country country;

struct country{
    char name[50];
    int gold;
    int silver;
    int bronze;
};

int compare(country a, country b){
    if(a.gold != b.gold){
        return a.gold < b.gold;
    }
    if(a.silver != b.silver){
        return a.silver < b.silver;
    }
    return a.bronze < b.bronze;
}

void swap(country *a, country *b){
    country temp = *a;
    *a = *b;
    *b = temp;
}

void sort_countries(country arr[], int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(compare(arr[j], arr[j + 1])){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    country arr[n];

    for(int i = 0; i < n; i++){
        scanf("%s %d %d %d", arr[i].name, &arr[i].gold, &arr[i].silver, &arr[i].bronze);
    }

    sort_countries(arr, n);

    for(int i = 0; i < n; i++){
        printf("%s\n", arr[i].name);
    }
}