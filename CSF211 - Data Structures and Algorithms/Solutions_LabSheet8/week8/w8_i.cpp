#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    set<int> ans;
    for(int i = 1; i <= k; i++)
        ans.insert(i);
    
    set<int> lost_one;

    for(int i = 0; i < n; i++){
        int w, l;
        cin >> w >> l;

        if(lost_one.count((l))){
            ans.erase(l);
        }
        else{
            lost_one.insert(l);
        }
    }

    for(auto x : ans) cout << x << " ";

    return 0;
}