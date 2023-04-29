#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    set<int> s;
    for (int i = 0; i < q; ++i) {
        int type, k;
        cin >> type >> k;
        if (type == 1) {
            if (s.count(k))
                s.erase(k);
            else
                s.insert(k);
        } else if (type == 2) {
            auto it = s.lower_bound(k);
            if (it == s.end())
                cout << -1 << "\n";
            else
                cout << *it << "\n";
        } else {
            auto it = s.upper_bound(k);
            if (it == s.begin())
                cout << -1 << "\n";
            else
            {
                it--;
                cout << *it << "\n";
            }
        }
    }

    return 0;
}