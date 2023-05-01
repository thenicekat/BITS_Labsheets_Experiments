#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/G.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        string input;
        cin >> input;

        int n = input.size();

        int answer = 0;

        // isPalindrome if substring i...j is palindrome
        int isPalindrome[n + 1][n + 1];
        memset(isPalindrome, 0, sizeof(isPalindrome));

        // We need to make all the substrings with size 1 as 1
        for (int i = 0; i < n; i++)
        {
            isPalindrome[i][i] = 1;
            answer++;
        }

        // We start with 2 sized substrings
        for (int gap = 2; gap <= n; gap++)
        {
            // then we check for every possible end with gap 2
            for (int m = 0; m <= n - gap; m++)
            {
                int endingPoint = gap + m - 1;

                if (m == endingPoint - 1)
                {
                    isPalindrome[m][endingPoint] = (input[m] == input[endingPoint]);
                }
                else
                {
                    isPalindrome[m][endingPoint] = (input[m] == input[endingPoint]) && (isPalindrome[m + 1][endingPoint - 1] == 1);
                }

                if(isPalindrome[m][endingPoint] == 1){
                    answer++;
                }
            }
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}