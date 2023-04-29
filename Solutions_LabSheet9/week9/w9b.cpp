#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> pref(n);
    pref[0] = s[0] == '*';
    for (int i = 1; i < n; ++i) {
        pref[i] = s[i] == '*';
        pref[i] += pref[i - 1];
    }
    
    vector<int> nxt(n);
    nxt[n - 1] = n;
    for (int i = n - 2; i >= 0; --i)
        nxt[i] = s[i] == '|' ? i : nxt[i + 1];
    
    vector<int> prv(n);
    prv[0] = -1;
    for (int i = 1; i < n; ++i)
        prv[i] = s[i] == '|' ? i : prv[i - 1];
    
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        if (nxt[l] <= prv[r]) {
            ans += pref[prv[r]];
            if (nxt[l] > 0)
                ans -= pref[nxt[l] - 1];
        }
        cout << ans << "\n";
    }

    return 0;
}