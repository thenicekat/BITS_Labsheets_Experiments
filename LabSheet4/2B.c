#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

void main()
{
    FILE *file;
    file = fopen("2B.txt", "r");

    int numH;
    fscanf(file, "%d", &numH);

    int input[numH];
    for (int i = 0; i < numH; i++)
    {
        fscanf(file, "%d", &input[i]);
    }

    int answer = 0;

    int left = 0;
    int right = numH;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int score = 0;
        for (int i = 0; i < numH; i++)
        {
            if (input[i] >= mid)
                score++;
        }

        if (score == mid)
        {
            answer = max(answer, mid);
        }
        
        if (score < mid)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%d", answer);
}