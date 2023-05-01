// knapsack only I think

#include <bits/stdc++.h>
using namespace std;

int checkSum(vector<vector<int>> dp, int input[], int index, int neededSum){
    // cout << index << " " << neededSum << endl;
    // if sum = 0 return true
    if(neededSum == 0){
        return 1;
    }

    if(index == -1){
        return 0;
    }

    if(dp[index][neededSum] != -1){
        return dp[index][neededSum];
    }

    if(neededSum >= input[index]){
        return (checkSum(dp, input, index - 1, neededSum - input[index]) || checkSum(dp, input, index - 1, neededSum));
    }else{
        return checkSum(dp, input, index - 1, neededSum);
    }
}

int main()
{
    freopen("Inputs/J.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        int inLen, sum;
        cin >> inLen >> sum;

        int input[inLen];
        for (int i = 0; i < inLen; i++)
        {
            cin >> input[i];
        }

        vector<vector<int>> dp(inLen + 1, vector<int> (sum + 1, -1));

        cout << (checkSum(dp, input, inLen-1, sum) == 1 ? "Yes" : "No") << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}