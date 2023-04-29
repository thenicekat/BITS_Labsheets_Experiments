#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> l(n), r(n);

    for(int i = 0; i < n; i++){
        string arr, dep;
        cin >> arr >> dep;

        l[i] = stoi(arr);
        r[i] = stoi(dep);
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
        
    int ans = 0;
        
    for(int i = 0; i < n; i++){
        
        int j = i, cnt = 0;
        
        while(j < n && l[j] == l[i]){
            cnt++;
            j++;
        }

        i = j - 1;
        ans = max(ans, cnt);
    }
        
        
    for(int i = 0 ; i < n; i++){
        if(i && r[i] == r[i - 1]) continue;
            
        int left_before = upper_bound(l.begin(), l.end(), r[i]) - l.begin();
        int right_before = lower_bound(r.begin(), r.end(), r[i]) - r.begin();
            
        ans = max(ans, left_before - right_before);
    }

    cout << ans << endl;

    return 0;
}