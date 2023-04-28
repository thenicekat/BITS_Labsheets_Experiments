// we can recurse and iterate I feel but idk dp so maybe should learn first
// Here sub problem can be bags of smaller size
// but that would O(n*w)
// so we need to optimize it
#include <bits/stdc++.h>
using namespace std;

// This function returns the min weight sum that can be possible for a given score
int gymbag(vector<vector<int>> &dp, int scoreSum, int index, vector<int> weights, vector<int> scores, int maxLength){
    // If the sum of scores becomes 0 that means we have reached end and return 0
    if(scoreSum <= 0){
        return 0;
    }

    // here we check if the index goes out of bounds, as in 
    // if it goes out of bounds then answer is just the max weight
    // like we iterate and we keep increasing index na if it reached outside the array
    // that means we still need some more weights 
    if(index == maxLength){
        return 100;
    }

    if(dp[index][scoreSum] != -1){
        return dp[index][scoreSum];
    }

    return dp[index][scoreSum] = min(
        gymbag(dp, scoreSum, index + 1, weights, scores, maxLength),
        weights[index] + gymbag(dp, scoreSum - scores[index], index + 1, weights, scores, maxLength)
        );
}

int main()
{
    freopen("Inputs/A.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        // take input
        int len, needed;
        cin >> len >> needed;

        vector<int> weights, scores;

        int sumOfScores = 0;

        // Here we just take input and find the value of sum of scores
        for (int i = 0; i < len; i++)
        {
            int wt, val;
            cin >> wt >> val;
            weights.push_back(wt);
            scores.push_back(val);
            sumOfScores += val;
        }

        vector<vector<int>> vec(len + 1, vector<int> (sumOfScores + 1, -1));

        // Now we iterate through all the possible scores which goes from 0 to sumOfScores
        // we go in reverse so as to get the answer meaning automatically we get maximum value
        int found = 0;
        for (int i = sumOfScores; i >= 0 && found == 0; i--)
        {   
            // So we iterate and find the max weight which we can get at that value
            // it goes from 140 to 0 in TC1
            int weight = gymbag(vec, i, 0, weights, scores, len);
            if(weight <= needed){
                cout << i << endl;
                found = 1;
            }
        }
        if(found == 0){
            cout << 0 << endl;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}