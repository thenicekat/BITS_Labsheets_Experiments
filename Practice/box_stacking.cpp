#include <bits/stdc++.h>
using namespace std;

bool compareFunc(vector<int> box1, vector<int> box2){
    return box2[2] > box1[2];
}

int stack_boxes(vector<vector<int>> boxes){
    sort(boxes.begin(), boxes.end(), compareFunc);

    int n = boxes.size();

    vector<int> dp(n + 1, 0);

    int height = 1;
    for(int i=0; i<n; i++){
        dp[i] = boxes[i][2];
    }

    

}

int main(){
    vector<vector<int>> boxes = {
         {2,1,2},{3,2,3},{2,2,8},{2,3,4},{2,2,1},{4,4,5}
    };


}