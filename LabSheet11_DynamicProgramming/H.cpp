// so in this question we know that end has to be a )
// if end is a ( we just ignore
// if end is ) and end - 1 is ( then we do dp[i] = dp[i-2] + 2;
// if end is ) and end - 1 is also ( then if input[i-1 + dp[i-1]]

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/H.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        string input;
        cin >> input;

        // Here dp represents the largest length of RBS in the string from 0, i;
        int dp[input.size()] = {0};
        int maxans = 0;

        // we loop through all the possible characters
        for (int i = 0; i < input.size(); i++)
        {
            // we check if it's a closing bracket
            if (input[i] == ')')
            {
                // if the one before is a closing bracket, then it will become part of the largest string + these 2 characters
                if (input[i - 1] == '(')
                {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                // then we check if the previous one is also a closing bracket
                // then we have a check to see if the dp[i-1] which means the largest rbs till there
                // is less than i 
                // we also check if there's an rbs like that then, does it start with a opening bracket
                // if yes then dp[curr] = dp[the word - the curr] + dp[]
                // in conclusion, this is basically checking if it has an opening bracket before
                else if (i > dp[i - 1] && input[i - 1 - dp[i - 1]] == '(')
                {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }

                maxans = max(maxans, dp[i]);
            }
        }

        for(auto x: dp){
            cout << x << " ";
        }
        cout << endl;

        cout << maxans << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}