#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    long long sum = 0;
    map<long long, int> mp;
    mp[0] = 1;
    
    long long ans = 0;
    for (auto &x : a) {
        sum += (x - k);
        if (mp.count(sum))
            ans += mp[sum];
        mp[sum]++;
    }

    cout << ans << "\n";

    return 0;
}