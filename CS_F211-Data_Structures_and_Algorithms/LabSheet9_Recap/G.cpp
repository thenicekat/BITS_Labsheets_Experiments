// lexographic sort of numbers?

#include <bits/stdc++.h>
using namespace std;

int myCompareFunction(string x, string y){
    string xy = x + y;
    string yx = y + x;
    return xy < yx;
}

int main(){
    freopen("Inputs/G.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inLen; 
        cin >> inLen;

        string input[inLen];
        for(int i=0; i<inLen; i++){
            cin >> input[i];
        }

        sort(input, input + inLen, myCompareFunction);

        for(int i=inLen - 1; i >= 0; i--){
            cout << input[i];
        }
        cout << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}