// https://www.geeksforgeeks.org/maximum-length-possible-by-cutting-n-given-woods-into-at-least-k-pieces/

#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

void main()
{
    FILE *file;
    file = fopen("J.txt", "r");

    int numH, numNeeded;
    int counter = 0, maxElem = 0;
    fscanf(file, "%d %d", &numH, &numNeeded);

    int input[numH];
    for (int i = 0; i < numH; i++)
    {
        fscanf(file, "%d", &input[i]);
        counter += input[i];
        maxElem = max(maxElem, input[i]);
    }

    int answer = 0;

    if (counter < numNeeded)
    {
        printf("%d", 0);
        return;
    }
    else
    {
        int left = 1;
        int right = maxElem;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int x;

            for (int i = 0; i < numH; i++)
            {
                x += input[i] / mid;
            }

            if (x >= numNeeded)
            {
                answer = max(answer, mid);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        printf("%d", answer);
    }
}