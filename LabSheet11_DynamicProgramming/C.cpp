// modified version of LCS
// basically replacing means we remove both characters and count
// insert meaning, we add one to the insertion wala and count
// remove meaning we remove one and count

// so it's like we have horse and ros
// we start from end
// since they are not same, we see minimum of all
// Replacing matlab last will be same and we check in hors and ro -> index_a - 1 and index_b - 1 
// Inserting matlab horse and rose will be compared meaning we start from -> index_a and index_b - 1
// Removing meaning we will have hors and ros -> index_a - 1 and index_b

#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z); }

int dp[10000][10000];

int editDistance(string a, string b, int index_a, int index_b)
{
    // Debug: Print Indices
    if (index_a == 0)
    {
        return dp[index_a][index_b] = index_b;
    }

    if (index_b == 0)
    {
        return dp[index_a][index_b] = index_a;
    }

    if(dp[index_a][index_b] != -1){
        return dp[index_a][index_b];
    }

    if (a[index_a - 1] == b[index_b - 1])
    {
        return dp[index_a][index_b] = editDistance(a, b, index_a - 1, index_b - 1);
    }
    else
    {
        return dp[index_a][index_b] = 1 + min(
            editDistance(a, b, index_a, index_b - 1), // Inserting one into a
            editDistance(a, b, index_a - 1, index_b - 1), // Replacing both characters meaning we ignore both
            editDistance(a, b, index_a - 1, index_b) // Removing the one in b
        );
    }
}

int main()
{
    freopen("Inputs/C.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        // take input
        int inLenA;
        cin >> inLenA;
        string a;
        cin >> a;

        int inLenB;
        cin >> inLenB;
        string b;
        cin >> b;

        memset(dp, -1, sizeof(dp));

        cout << editDistance(a, b, inLenA, inLenB) << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}