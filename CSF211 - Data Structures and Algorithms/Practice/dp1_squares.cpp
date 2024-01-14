#include <bits/stdc++.h>
using namespace std;

int dpSoln(int k, vector<int> &dp)
{
    if(k <= 3){
        return dp[k] = k;
    }

    int sqr = sqrt(k);
    if (sqr * sqr == k)
    {
        return dp[k] = 1;
    }

    int answer = INT_MAX;

    for (int i = 1; i*i < k; i++)
    {
        if (dp[i*i] != 0 && dp[k - i*i] != 0)
        {
            answer = min(answer, dp[i*i] + dp[k - i*i]);
        }
        else
        {
            answer = min(answer, dpSoln(i*i, dp) + dpSoln(k - i*i, dp));
        }
    }

    return dp[k] = answer;
}

int main()
{
    int n;
    cin >> n;
    cout << "Q: " << n << endl;
    vector<int> dp(2 * n, 0);
    dp[1] = 1;
    cout << "Ans: " << dpSoln(n, dp) << endl;
}