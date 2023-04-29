#include <bits/stdc++.h>
#include <cinttypes>
#include <queue>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0 ; i < n; i++) cin >> a[i];

    priority_queue<int> mx_heap(a.begin(), a.end());

    int ans = 0;
    while(!mx_heap.empty() && k){
        k--;
        int largest = mx_heap.top();
        mx_heap.pop();
        ans += (largest + 1) / 2;
        mx_heap.push(largest / 2);
    }

    cout << ans << endl;
}