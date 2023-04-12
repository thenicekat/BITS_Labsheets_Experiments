// Test Case 1: 4
// petrolGiven 4 6 7 4
// petrolUsed 6 5 3 5
// Differences = -2 1 4 -1
// If we use prefixsum we get 2 but answer should be 1
// prefixSum of differences 

// Test Case 2: 4
// petrolGiven 55 52 33 100
// petrolUsed 77 61 40 69
// Differences = -22 -9 -7 -31
// Answer -1

// Test Case 3:
// petrolGiven 1 2 3 4 5 6
// petrolUsed  2 3 4 5 6 1
// differences -1 -1 -1 -1 -1 5

// Maybe I should think of stack :)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/I.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inLen;
        cin >> inLen;

        int a[inLen], b[inLen];
        for (int i = 0; i < inLen; i++)
            cin >> a[i];
        for (int i = 0; i < inLen; i++)
            cin >> b[i];

        int difference[inLen];
        int canHappen = 0;
        for (int i = 0; i < inLen; i++){
            difference[i] = a[i] - b[i];
            canHappen += difference[i];
        }

        if(canHappen < 0){
            cout << -1 << endl;
        }else{
            stack<int> st;
            int answer = 0;
            int sum = 0;
            for(int i=0; i<inLen; i++){
                sum += difference[i];
                st.push(difference[i]);

                if(sum < 0){
                    sum -= st.top();
                    st.pop();
                    answer++;
                }
            }

            cout << answer << endl;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}