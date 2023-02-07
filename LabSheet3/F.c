#include <stdio.h>

int getLastOccurence(int input[], int n, int x)
{
    int start = 0;
    int end = n - 1;

    int result = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (input[mid] == x)
        {
            result = mid;
            start = mid + 1;
        }
        else if (input[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    printf("::> %d %d\n", x, result);
    return result;
}

void main()
{
    FILE *file;
    file = fopen("F.txt", "r");

    int n;
    fscanf(file, "%d", &n);

    int input[n];

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &input[i]);
    }

    int answer = 0;
    int curr = 0;

    while (curr < n)
    {
        curr = getLastOccurence(input, n, input[curr]) + 1;
        answer++;
    }

    printf("Answer: %d", answer);
}