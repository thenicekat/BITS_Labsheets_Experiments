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

int main(){
    freopen("Inputs/E.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int m, k, n;
        cin >> m >> k >> n;
        
        // O(p)
        int p;
        cin >> p;
        map<pair<int, int>, int> matrixA;
        for(int i=0; i<p; i++){
            int a, b, c;
            cin >> a >> b >> c;
            matrixA[{a, b}] = c;
        }

        map<pair<int, int>, int> result;

        // O(q)
        int q;
        cin >> q;
        map<pair<int, int>, int> matrixB;
        for(int i=0; i<q; i++){
            int a, b, c;
            cin >> a >> b >> c;
            matrixB[{a, b}] = c;
        }



        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}