#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> k(n);

    for(int i = 0; i < n; i++){
        cin >> k[i];
        a[i] = vector<int>(k);
        for(int j = 0; j < k[i]; j++)
            cin >> a[i][j];
    }

    vector<int> ptr(n, 0);
    multiset<pair<int, int>> pq;
    for(int i = 0; i < n; i++)
        pq.insert({a[i][0], i});
    
    vector<int> ans;
    while(!pq.empty()){
        pair<int, int> smallest = *pq.begin();
        pq.erase(smallest);
        ans.push_back(smallest.first);
        int idx = smallest.second;
        ptr[idx]++;
        if(ptr[idx] < k[idx])
            pq.insert({a[idx][ptr[idx]], idx});
    }

    for(auto x : ans)
        cout << x << " ";
    
    cout << endl;
}