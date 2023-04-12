// use priority queue :) and remove the least negative numbers
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Inputs/A.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int sumTracker = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        int lenK;
        cin >> lenK;

        int answer = lenK;

        for(int i= 0; i<lenK; i++){
            int num;
            cin >> num;

            // First add number to sum and push to queue
            sumTracker += num;
            pq.push(num);

            // check if sum <0
            if(sumTracker < 0){
                sumTracker -= pq.top();
                cout << "Removing: " << pq.top() << endl;
                pq.pop();
                answer--;
            }

        }

        cout << answer << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}