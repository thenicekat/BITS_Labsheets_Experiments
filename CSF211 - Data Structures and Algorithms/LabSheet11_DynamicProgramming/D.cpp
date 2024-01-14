// https://www.youtube.com/watch?v=Tw1k46ywN6E&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&t=3603s

#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int blessings(int input[], int start, int end){
    if(start > end){
        return dp[start][end] = 0;
    }
    if(start == end){
        return dp[start][end] = input[start];
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }

    int ifWeTakeStart = input[start] + min(blessings(input, start+2, end), blessings(input, start+1, end-1));
    int ifWeTakeEnd = input[end] + min(blessings(input, start+1, end-1), blessings(input, start, end-2));

    return dp[start][end] = max(ifWeTakeStart, ifWeTakeEnd);
}

int main(){
    freopen("Inputs/D.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++){
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        int inLen, totalSum = 0;
        cin >> inLen;

        int input[inLen];
        for(int i=0; i<inLen; i++){
            cin >> input[i];
            totalSum += input[i];
        }

        memset(dp, -1, sizeof(dp));

        int vidya = blessings(input, 0, inLen - 1);
        int hom = totalSum - vidya;

        cout << ((vidya > hom) ? "Vidyateja" : "Hom") << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}