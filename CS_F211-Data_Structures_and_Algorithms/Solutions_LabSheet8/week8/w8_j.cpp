#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> a(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i+1];
    }

    vector<int> pref(n+1, 0);
    map<int, int> mp;
    mp[0] = 0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i];
        if(!mp.count(pref[i])){
            mp[pref[i]] = i;
        }
    }

    for(int i = 1; i <= k; i++){
        mp[pref.back() + i] = n;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int j = mp[pref[i - 1] + k];
        ans += j - i + 1;
    }

    cout << ans << endl;
}