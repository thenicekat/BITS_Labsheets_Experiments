// Simply merge intervals?
#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("Inputs/J.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inLen;
        cin >> inLen;

        // Take input O(n)
        pair<int, int> input[inLen];
        for(int i=0; i<inLen; i++){
            cin >> input[i].first;
            cin >> input[i].second;
        }

        sort(input, input + inLen);

        int answer = 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<inLen; i++){
            while(!pq.empty() && input[i].first > pq.top()){
                pq.pop();
            }

            pq.push(input[i].second);

            answer = max(answer, (int) pq.size());
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}