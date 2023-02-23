#include <stdio.h>

#define int long long int

void main()
{
    FILE *file;
    file = fopen("B.txt", "r");

    int noOfTestCases;
    fscanf(file, "%lld", &noOfTestCases);

    for (int i = 0; i < noOfTestCases; i++)
    {
        printf("---------Test Case No: %lld-----------\n", i);

        int answer;
        fscanf(file, "%lld", &answer);

        int start = 1;
        int end = answer;

        // We create a variable to keep track of whether we need to cut
        // from start or from end
        // We initialize a jump variable with initial jump = 1
        // And perform a loop until size becomes 1

        // Example 1 2 3 4 5 6 7 8 9 10 11 12 -> size = 12 start = 1 end = 12
        // After first iteration jump becomes 2 and 
        // should become 2 4 6 8 10 12
        // our series = 2 3 4 5 6 7 8 9 10 11 12 size = 6 start = 2 end = 12
        // should become 2 6 10
        // since size is even and we go from reverse we need to remove right
        // series 2 3 4 5 6 7 8 9 10 size = 3 start = 2 end = 10
        // since size if odd and we are going from start

        int size = answer;
        int jump = 1;
        int fromStart = 1;

        while (start < end && size > 1)
        {
            if (fromStart)
            {
                // Case where we are eliminating from start
                if (size % 2 == 0)
                {
                    start += jump;
                }
                else
                {
                    start += jump;
                    end -= jump;
                }
                fromStart = 0;
            }
            else
            {
                if (size % 2 == 0)
                {
                    end -= jump;
                }
                else
                {
                    start += jump;
                    end -= jump;
                }
                fromStart = 1;
            }

            jump *= 2;
            size /= 2;
        }
        printf("%lld", start);
        printf("\n------------------------------------\n");
    }
}