// 5 5
// 1 4 7 11 15
// 2 5 8 12 19
// 3 6 9 16 22
// 10 13 14 17 24
// 18 21 23 26 30
// 5

// We loop through first row and eliminate some columns
// we loop through first column and eliminate some rows
// We will have
// 1 4
// 2 5
// 3 6
// We loop through last row and last column and eliminate some rows and columns 
// but idk if we can make that or not
// We can remove 1 4
// hmmm we can do this
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

        int rightMostColumn = 0, bottomMostRow = 0, topMostRow = 0, leftMostColumn = 0;

        // First we loop through the top row :)
        for(int i=0; i<n; i++){
            if(input[0][i] < toFind){
                rightMostColumn = i;
            }
        }

        // Then we loop through the left column :)
        for(int i=0; i<m; i++){
            if(input[i][0] < toFind){
                bottomMostRow = i;
            }
        }

        // Then we loop through the bottom most row of the new matrix
        for(int i=0; i<rightMostColumn; i++){
            if(input[top][i] < toFind){
                leftMostColumn++;
            }
        }

        // Then we loop through the leftMostColumn to find the topMostRow
        for(int i=0; i<bottomMostRow; i++){
            if(input[i][rightMostColumn] < toFind){
                topMostRow++;
            }
        }

        for(int i=topMostRow; i<=bottomMostRow; i++){
            for(int j=leftMostColumn; j<=rightMostColumn; j++){
                cout << input[i][j] << " ";
            }
            cout << endl;
        }

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}