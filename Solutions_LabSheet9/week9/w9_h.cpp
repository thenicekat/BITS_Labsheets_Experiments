#include <bits/stdc++.h>

using namespace std;



int main(){

    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = 0;
    
    for(auto x : a){
        l = max(l, x);
        r += x;
    }
    
    while(l < r){
        int mid = (l + r) / 2;
        int sum = 0;
        int cnt = 1;
        for(auto x : a){
            sum += x;
            if(sum > mid){
                cnt++;
                sum = x;
            }
        }
        
        if(cnt <= m){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    
    cout << l << endl;

    return 0;
}