// 5 5
// 1 4 7 11 15
// 2 5 8 12 19
// 3 6 9 16 22
// 10 13 14 17 24
// 18 21 23 26 30
// 5

// We start from top right corner and keep moving
// if number is higher than toFind, then we eliminate the column
// if number is lower than toFind, we eliminate the row
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Inputs/B.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take input 
        int m, n;
        cin >> m >> n;
        int input[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> input[i][j];
            }
        }

        int toFind;
        cin >> toFind;

        int col = n - 1;
        int row = 0;

        int found = 0;

        while(col >= 0 && row < m){
            if(input[row][col] == toFind){
                cout << "Yes" << endl;
                found = 1;
            }

            if(input[row][col] < toFind){
                row++;
            }else{
                col--;
            }
        }

        if(found == 0) cout << "No" << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}