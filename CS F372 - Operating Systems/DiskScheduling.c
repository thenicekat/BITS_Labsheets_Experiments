#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 100000

void fcfs(int queue[], int head, int n)
{
    int seek = 0;
    int diff;
    for (int i = 0; i < n; i++)
    {
        diff = abs(queue[i] - head);
        seek += diff;
        head = queue[i];
    }
    printf("\nTotal seek time: %d", seek);
}

void sst(int queue[], int head, int n)
{
    int curr = head;
    int minelem = 0;
    int seek = 0;

    for (int i = 0; i < n; i++)
    {
        int mindist = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (queue[j] != INT_MAX && abs(curr - queue[j]) < mindist)
            {
                mindist = abs(curr - queue[j]);
                minelem = j;
            }
        }
        printf("\n::> Choosing %d", queue[minelem]);
        curr = queue[minelem];
        queue[minelem] = INT_MAX;
        seek += mindist;
    }

    printf("\nTotal seek time: %d\n", seek);
}

void scan(int queue[], int head, int n, int max)
{
    int seek = 0;
    printf("\nEnter Direction (- = -1/+ = 1): ");
    int dir;
    scanf("%d", &dir);

    int curr = head;
    printf("\n::> Choosing %d", head);

    if (dir == 1)
    {
        // Going Right first till max
        for (int i = curr; i <= max; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (queue[j] != INT_MAX && queue[j] == i)
                {
                    seek += abs(i - curr);
                    curr = i;
                    printf("\n::> Choosing %d", queue[j]);
                    queue[j] = INT_MAX;
                }
            }
        }

        printf("\n::> Choosing %d", max);
        seek += abs(max - curr);
        curr = max;
        printf("\n%d", seek);

        // Going left till the last one
        for (int i = curr; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (queue[j] != INT_MAX && queue[j] == i)
                {
                    seek += abs(i - curr);
                    curr = i;
                    printf("\n::> Choosing %d", queue[j]);
                    queue[j] = INT_MAX;
                }
            }
        }

        printf("\nTotal seek time: %d\n", seek);
    }
    else if (dir == -1)
    {
        // Going Left first till 0
        for (int i = curr; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (queue[j] != INT_MAX && queue[j] == i)
                {
                    seek += abs(i - curr);
                    curr = i;
                    printf("\n::> Choosing %d", queue[j]);
                    queue[j] = INT_MAX;
                }
            }
        }
        printf("\n::> Choosing %d", 0);
        seek += abs(curr);
        curr = 0;
        // Going right till the last one
        for (int i = curr; i <= max; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (queue[j] != INT_MAX && queue[j] == i)
                {
                    seek += abs(i - curr);
                    curr = i;
                    printf("\n::> Choosing %d", queue[j]);
                    queue[j] = INT_MAX;
                }
            }
        }

        printf("\nTotal seek time: %d\n", seek);
    }
}

void cscan(int queue[], int head, int n, int max)
{
    int seek = 0;
    printf("\nEnter Direction (- = -1/+ = 1): ");
    int dir;
    scanf("%d", &dir);

    int curr = head;

    if (dir == 1)
    {
        // Going right till the last one
        for (int i = curr; i <= max; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (queue[j] != INT_MAX && queue[j] == i)
                {
                    seek += abs(i - curr);
                    curr = i;
                    printf("\n::> Choosing %d", queue[j]);
                    queue[j] = INT_MAX;
                }
            }
        }

        // Then we go to max
        printf("\n::> Choosing %d", max);
        seek += abs(max - curr);
        curr = max;

        // Then go to 0
        printf("\n::> Choosing %d", 0);
        seek += abs(curr);
        curr = 0;

        // Going Left first till 0
        for (int i = curr; i <= max; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (queue[j] != INT_MAX && queue[j] == i)
                {
                    seek += abs(i - curr);
                    curr = i;
                    printf("\n::> Choosing %d", queue[j]);
                    queue[j] = INT_MAX;
                }
            }
        }

        printf("\nTotal seek time: %d\n", seek);
    }
    else if (dir == -1)
    {
        // Going Left first till 0
        for (int i = curr; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (queue[j] != INT_MAX && queue[j] == i)
                {
                    seek += abs(i - curr);
                    curr = i;
                    printf("\n::> Choosing %d", queue[j]);
                    queue[j] = INT_MAX;
                }
            }
        }

        printf("\n::> Choosing %d", 0);
        seek += abs(curr);
        curr = 0;

        // Then we go to the other end
        printf("\n::> Choosing %d", max);
        seek += abs(max - curr);
        curr = max;

        // Going right till the last one
        for (int i = curr; i <= max; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (queue[j] != INT_MAX && queue[j] == i)
                {
                    seek += abs(i - curr);
                    curr = i;
                    printf("\n::> Choosing %d", queue[j]);
                    queue[j] = INT_MAX;
                }
            }
        }

        printf("\nTotal seek time: %d\n", seek);
    }
}

int main()
{
    int queue[] = {2069, 1212, 2296, 2800, 544, 1618, 356, 1523, 4965, 3681};
    int max = 4999;
    int head = 2150;
    int n = 10;

    printf("\n1. FCFS\n2. Shortest Seek Time\n3. SCAN\n4. C SCAN\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        fcfs(queue, head, n);
        break;
    case 2:
        sst(queue, head, n);
        break;
    case 3:
        scan(queue, head, n, max);
        break;
    case 4:
        cscan(queue, head, n, max);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}