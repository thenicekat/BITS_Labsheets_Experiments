#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int l = 0, r = n / 2;

    int ans = 0;

    while(l < n/2 && r < n){
        
        while(r < n && a[r] - a[l] < k) 
            r++;
        
        if(r == n)
            break;
        
        ans++;
        l++;
        r++;
    }

    cout << ans << endl;

    return 0;
}