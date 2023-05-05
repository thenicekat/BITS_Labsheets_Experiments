// similar to normal knapsack I feel
// if fraction comes print -1 
// otherwise print size :)
// I think it's an unbounded knapsack more or less

#include <bits/stdc++.h>
using namespace std;

int couponChange(vector<vector<int>> dp, int input[], int index, int needed){
    // cout << index << " " << needed << endl;
    if(needed == 0){
        return dp[index][needed] = 0;
    }
    
    if(index == 0){
        return 1000000000;
    }
    
    if(input[index - 1] <= needed)
        return dp[index][needed] = min(
            1 + couponChange(dp, input, index, needed - input[index - 1]), 
            couponChange(dp, input, index - 1, needed)
        );
    else
        return dp[index][needed] = couponChange(dp, input, index - 1, needed);
}

int main(){
    freopen("Inputs/F.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++){
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        int inLen, needed;
        cin >> inLen >> needed;
        int input[inLen];
        for(int i=0; i<inLen; i++){
            cin >> input[i];
        }

        vector<vector<int>> dp(inLen + 1, vector<int> (needed + 1, -1));

        int answer = couponChange(dp, input, inLen, needed);
        if(answer == 1000000000){
            cout << -1 << endl;
        }else{
            cout << answer << endl;
        }

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}