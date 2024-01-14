#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    map<int, int> cnt;
    set<int> s;
    for (int i = 0; i < m; ++i) {
        cnt[a[i]]++;
        if (cnt[a[i]] == k)
            s.insert(a[i]);
        else if (cnt[a[i]] == k + 1)
            s.erase(a[i]);
    }
    if (!s.empty())
        cout << *s.rbegin() << "\n";
    else
        cout << -1 << "\n";

    for (int i = m; i < n; ++i) {
        cnt[a[i - m]]--;
        if (cnt[a[i - m]] == k)
            s.insert(a[i - m]);
        else if (cnt[a[i - m]] == k - 1)
            s.erase(a[i - m]);

        cnt[a[i]]++;
        if (cnt[a[i]] == k)
            s.insert(a[i]);
        else if (cnt[a[i]] == k + 1)
            s.erase(a[i]);

        if (!s.empty())
            cout << *s.rbegin() << "\n";
        else
            cout << -1 << "\n";
        
    }

    return 0;
}