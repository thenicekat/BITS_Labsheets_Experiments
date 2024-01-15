// https://www.geeksforgeeks.org/reservoir-sampling/
// https://www.youtube.com/watch?v=A1iwzSew5QY
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// We need time library to seed random numbers randomly

#define int long long int

void main(){
    FILE* file;
    file = fopen("J.txt", "r");
    
    srand(time(NULL));
    int temp, count = 0, store;

    // We initialize variables
    while(fscanf(file, "%lld", &temp) != -1){
        // Every loop count increases
        count++;

        // Generate random numbers from 0 to count - 1
        int i = rand() % count;

        // If count == 1, just print the first one
        // Otherwise we change number only if random number becomes count - 1
        // else it'll be same as previous input
        if(count == 1) store = temp;
        else if(i == count - 1){
            store = temp;
        }

        printf("%lld\n", store);
    }
}