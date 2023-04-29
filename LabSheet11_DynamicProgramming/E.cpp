// C(i, j) = min(C(i, k-1) + C(k, j) + l_i*l_k-1*l_j)

#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int matrixChain(int i, int j, int dim[])
{
    if(i == j)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int minChain = INT_MAX;
    for (int m = i; m < j; m++)
    {
        minChain = min(minChain, matrixChain(i, m, dim) + matrixChain(m + 1, j, dim) + dim[i-1]*dim[m]*dim[j]);
    }
    return dp[i][j] = minChain;
}

int main()
{
    freopen("Inputs/E.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        memset(dp, -1, sizeof(dp));

        int x;
        cin >> x;

        int inLen = x + 1;

        int dim[inLen];
        for (int i = 0; i < inLen; i++)
        {
            cin >> dim[i];
        }

        cout << matrixChain(1, inLen - 1, dim) << endl;

            cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}