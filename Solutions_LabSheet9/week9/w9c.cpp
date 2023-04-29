#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    long res = 0, j, k;
    stack<int> s;
    for (int i = 0; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] > (i == n ? -2e9 : a[i]))
        {
            j = s.top(), s.pop();
            k = s.empty() ? -1 : s.top();
            res -= (long)a[j] * (i - j) * (j - k);
        }
        s.push(i);
    }
    s = stack<int>();
    for (int i = 0; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] < (i == n ? 2e9 : a[i]))
        {
            j = s.top(), s.pop();
            k = s.empty() ? -1 : s.top();
            res += (long)a[j] * (i - j) * (j - k);
        }
        s.push(i);
    }
    cout << res << "\n";

    return 0;
}