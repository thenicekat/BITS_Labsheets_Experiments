#include <bits/stdc++.h>
#include <cinttypes>
#include <functional>
#include <queue>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n), b(n);
    for(int i = 0 ; i < n; i++) cin >> a[i];
    for(int i = 0 ; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    priority_queue<pair<int, pair<int, int>>> mx_heap;
    mx_heap.push({a[n - 1] + b[n - 1],{n - 1, n - 1}});

    set<pair<int, int>> vis;
    vis.insert({n - 1, n - 1});

    vector<int> ans;

    while(k--){
        auto largest = mx_heap.top();
        mx_heap.pop();
        int posa = largest.second.first;
        int posb = largest.second.second;
        int sum = largest.first;

        ans.push_back(sum);

        if(posa - 1 >= 0 && !vis.count({posa - 1, posb})){
            vis.insert({posa - 1, posb});
            mx_heap.push({a[posa - 1] + b[posb], {posa - 1, posb - 1}});
        }

        if(posb - 1 >= 0 && !vis.count({posa, posb - 1})){
            vis.insert({posa, posb - 1});
            mx_heap.push({a[posa] + b[posb - 1], {posa - 1, posb - 1}});
        }
    }

    for(auto x : ans)
        cout << x << " ";

    return 0;
}