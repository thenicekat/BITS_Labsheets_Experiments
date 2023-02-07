#include <stdio.h>
#define int long long

void main()
{
    int input;
    scanf("%d", &input);

    int halfWayPoint = (input * (input + 1)) / 4;

    int start = 0;
    int end = input - 1;

    while (start < end)
    {
        int x = ((end * (end + 1)) / 2) - ((start * (start + 1)) / 2);
        if (x > halfWayPoint)
        {
            if(start != (start+end)/2) start = (start + end) / 2;
        }
        else break;
    }

    printf("%d", end-start);
}