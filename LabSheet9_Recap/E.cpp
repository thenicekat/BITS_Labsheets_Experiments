// Sparse Matrix
// We only multiply if the numbers are non zero
// Matrix A
// (1, 1) = 1
// (2, 1) = -1
// (2, 3) = 3

// Matrix B
// (1, 1) = 7 -> (1, 3) = 7
// (3, 3) = 1 -> (3, 1) = 1

// Result
// (1, 1) = 7
// (2, 1) = -7
// (2, 3) = 3

// We store on matrix in map
// and loop through the other one
// Say we loop through B
// Then first loop with (1, 1)
// in this loop, we have result[{ 1, 1 }] += matA[{ 1, 1 }] * matB[{ 1, 1 }]

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/E.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int m, k, n;
        cin >> m >> k >> n;

        // O(p)
        int noOfElementsP;
        cin >> noOfElementsP;
        map<
            int,
            map<pair<int, int>, int>>
            matrixA;

        for (int i = 0; i < noOfElementsP; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            matrixA[b][{a, b}] = c;
        }

        // Debugging :)
        // for(auto x: matrixArows){
        //     cout << x.first << endl;
        //     for(auto m: x.second){
        //         cout << m.first.first << " " << m.first.second << "->" << m.second << endl;
        //     }
        // }

        map<pair<int, int>, int>
            result;

        int noOfElementsQ;
        cin >> noOfElementsQ;
        for (int i = 0; i < noOfElementsQ; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            for (auto x : matrixA[a])
            {
                result[{x.first.first, b}] += c * x.second;
            }
        }

        int counter = 0;
        for (auto x : result)
        {
            counter++;
        }

        cout << counter << endl;

        for (auto x : result)
        {

            cout << x.first.first << " " << x.first.second << " " << x.second << endl;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}