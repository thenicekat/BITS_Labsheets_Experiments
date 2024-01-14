#include <stdio.h>
#include <limits.h>
#define int long long

int sum(int a) {
    return (a*(a+1))/2;
}

int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

void main()
{
    int input;
    scanf("%d", &input);

    int halfWayPoint = sum(input-1) / 2;
    printf("The Halfway point is: %lld\n", halfWayPoint);

    int start = 0;
    int end = input - 1;

    int answer = 0;

    while (start <= end)
    {
        int mid = (start + end)/2;
        printf("%lld %lld %lld\n", start, mid, end);
        int diff = sum(input-1) - sum(mid); 
        //here we subtract the number from total sum
        //say we have input as 10
        //total sum = 45 
        //mid sum will be 10
        //diff will be 35
        //if diff > halfway which here is 22
        //we consider this
        //that would mean number is below mid :)
        if(diff > halfWayPoint){
            answer = max(answer, mid);
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    printf("\n%lld", input-1-answer);
}