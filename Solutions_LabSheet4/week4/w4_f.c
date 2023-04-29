#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct pair pair;
struct pair{
    int first;
    int second;
};

void swap(pair *a, pair *b){
    pair temp = *a;
    *a = *b;
    *b = temp;
}

int compare(pair a, pair b){
    return a.first < b.first;
}

pair *merge_arr(pair *a, int n, pair *b, int m){

    pair *merged = malloc((n + m) * sizeof(pair));

    int ptr1 = 0, ptr2 = 0, ptr = 0;
    while(ptr1 < n && ptr2 < m){
        if(compare(a[ptr1], b[ptr2])){
            merged[ptr] = b[ptr2];
            ptr2++;
        }
        else{
            merged[ptr] = a[ptr1];
            ptr1++;
        }
        ptr++;
    }

    while(ptr1 < n){
        merged[ptr] = a[ptr1];
        ptr++;
        ptr1++;
    }

    while(ptr2 < m){
        merged[ptr] = b[ptr2];
        ptr++;
        ptr2++;
    }

    return merged;
}

pair* merge_sort(pair *arr, int n){

    if(n == 1){
        return arr;
    }

    int mid = n / 2;
    pair *left = malloc((mid) * sizeof(pair));
    pair *right = malloc((n - mid) * sizeof(pair));

    for(int i = 0; i < mid; i++)
        left[i] = arr[i];
    
    for(int i = 0; i < n - mid; i++)
        right[i] = arr[i + mid];

    left = merge_sort(left, mid);
    right = merge_sort(right, n - mid);

    return merge_arr(left,  mid, right, n - mid);
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n], count[MAX] = {0};
    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
        count[arr[i]]++;
    }

    pair freq[n];
    int len = 0;
    for(int i = 1; i < MAX; i++){
        if(count[i]){
            freq[len].first = count[i];
            freq[len].second = i;
            len++;
        }
    }

    pair *sorted = merge_sort(freq, len);

    for(int i = 0; i < k; i++){
        printf("%d ", sorted[i].second);
    }

    return 0;
}