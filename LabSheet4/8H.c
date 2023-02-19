#include <stdio.h>

#define int long long int

void main()
{
    FILE *file;
    file = fopen("8H.txt", "r");

    int kings, halls;
    fscanf(file, "%lld %lld", &kings, &halls);

    // Max Case is when all except room has 1 king and other room has the remaining 
    int maxKingsPerRoomMax = kings - halls + 1;
    int maxKingsPerRoomMin = 1;
    int maxAnswer = maxKingsPerRoomMax * (maxKingsPerRoomMax - 1) / 2;

    // Min Case is when the kings are as close to each other as possible
    int quotient = kings / halls;
    int reminder = kings % halls;
    int minAnswer = (halls - reminder)*quotient*(quotient-1)/2 + (reminder*quotient*(quotient+1))/2;

    printf("%lld %lld", minAnswer, maxAnswer);
}