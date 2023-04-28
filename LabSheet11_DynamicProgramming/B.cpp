// This is same as longest increasing subsequence
#include <bits/stdc++.h>
using namespace std;

int dp[10000][10000];

int lcs(int a[], int b[], int index_a, int index_b)
{
    // Debug: Print Indices
    if (index_a == 0 || index_b == 0)
    {
        return dp[index_a][index_b] = 0;
    }

    if(dp[index_a][index_b] != -1){
        return dp[index_a][index_b];
    }

    if (a[index_a - 1] == b[index_b - 1])
    {
        return dp[index_a][index_b] = 1 + lcs(a, b, index_a - 1, index_b - 1);
    }
    else
    {
        return dp[index_a][index_b] = max(lcs(a, b, index_a, index_b - 1), lcs(a, b, index_a - 1, index_b));
    }
}

int main()
{
    freopen("Inputs/B.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        // take input
        int inLenA;
        cin >> inLenA;
        int inputA[inLenA];
        for (int i = 0; i < inLenA; i++)
        {
            cin >> inputA[i];
        }

        int inLenB;
        cin >> inLenB;
        int inputB[inLenB];
        for (int i = 0; i < inLenB; i++)
        {
            cin >> inputB[i];
        }

        memset(dp, -1, sizeof(dp));

        cout << lcs(inputA, inputB, inLenA, inLenB) << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}