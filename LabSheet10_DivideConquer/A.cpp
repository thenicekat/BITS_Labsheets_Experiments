// Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/A.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inLen;
        cin >> inLen;
        int input[inLen];
        for (int i = 0; i < inLen; i++)
        {
            cin >> input[i];
        }

        int sum = 0;
        int maxSum = 0;
        for (int i = 0; i < inLen; i++)
        {
            // check if sum is negative
            if (sum < 0)
            {
                sum = input[i];
            }
            else
            {
                // Add the element
                sum += input[i];
            }
            
            maxSum = max(maxSum, sum);
        }

        cout << maxSum << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}