#include <stdio.h>

#define int long long int

void main(){
    FILE* file;
    file = fopen("H.txt", "r");
    
    int numOfInputs, mult;
    fscanf(file, "%lld %lld", &numOfInputs, &mult);

    int input[numOfInputs];
    
    // This question seems to be of type of sliding window + prefix sum since sum has to be divisible by the number mult
    // Also is the fact that we have contigous places given

    // Uhh apparently it's not
    // So basically in the prefix sum, say we have b and a
    // if b%k here k is 6
    // if b%6 = n and a%6 = n then (b-a)%6 = 0
    // Which gives us a sub array whose sum is a multiple of 6

    int reminders[mult];
    for(int i=0; i<mult; i++) reminders[i] = 0;

    int sum = 0;
    for(int i=0; i<numOfInputs; i++){
        // We take input from file
        fscanf(file, "%lld", &input[i]);
        // We generate cumulative sums
        sum += input[i];
        // We update array with cumulative sums
        input[i] = sum;
        // We update reminders array with mods
        reminders[sum % mult]++;
    }

    int answer = reminders[0];
    for(int i=0; i<mult; i++){
        if(reminders[i] > 1) answer += ((reminders[i])*(reminders[i]-1)/2);
    }

    printf("The number of subarrays: %lld", answer);
}