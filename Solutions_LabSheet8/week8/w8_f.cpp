#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int xr = 0;
    multiset<int> ms = {0};
    for(int i = 0; i < n; i++){
        xr = xr xor a[i];
        ms.insert(xr);
    }

    int ans = 0;
    while(!ms.empty()){
        int val = *ms.begin();
        int cnt = ms.count(val);
        ms.erase(val);
        ans += cnt * (cnt - 1) / 2;
    }

    cout << ans << endl;
}