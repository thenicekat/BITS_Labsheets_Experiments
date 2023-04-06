// Simply merge intervals?
#include <bits/stdc++.h>
using namespace std;

class Time{
    public:
    int begin;
    int end;
};

bool compare(Time a, Time b){
    return a.begin < b.begin;
}

int main(){
    freopen("Inputs/J.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inLen;
        cin >> inLen;

        // Take input O(n)
        Time input[inLen];
        for(int i=0; i<inLen; i++){
            cin >> input[i].begin;
            cin >> input[i].end;
        }

        // Sort them using compare O(nlogn)
        sort(input, input + inLen, compare);

        // Create a new array for answer
        Time answer[inLen];
        answer[0] = input[0];

        int counter = 0;
        int lastExit = input[0].end;
        for(int i=1; i<inLen; i++){
            if(input[i].begin <= lastExit){
                lastExit = max(lastExit, input[i].end);
                answer[i - 1].end = lastExit;
            }else{
                answer[++counter] = input[i];
                lastExit = max(lastExit, input[i].end);
            }
        }

        cout << inLen - counter << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}