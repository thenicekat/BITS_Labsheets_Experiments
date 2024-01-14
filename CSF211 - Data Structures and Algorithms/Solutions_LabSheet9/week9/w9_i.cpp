#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int tota = accumulate(a.begin(), a.end(), 0ll);
    int totb = accumulate(b.begin(), b.end(), 0ll);

    if(tota < totb){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    int prev = 0;

    for(int i = 0; i < n; i++){
        if(prev + a[i] < b[i]){
            ans = i + 1;
            prev = 0;
        }
        else{
            prev += a[i] - b[i];
        }
    }

    if(ans >= n){
        cout << -1 << endl;
    }

    else{
        cout << ans << endl;
    }

    return 0;
}