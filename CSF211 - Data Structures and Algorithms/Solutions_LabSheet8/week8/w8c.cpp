#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int x, y;
    cin >> x >> y;

    long long ans = 0;
    map<int, int> mp;
    for (int j = 0; j < n; ++j) {
        int num = a[j] - y * j;
        if (mp.count(num))
            ans += mp[num];
        mp[a[j] - x * j]++;
    }

    cout << ans << "\n";

    return 0;
}