#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    priority_queue<int> pq(a.begin(), a.end());
    for (int i = 0; i < m; ++i)
    {
        int mx = pq.top();
        pq.pop();
        pq.push(mx / 2);
    }

    long long sum = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }

    cout << sum << "\n";

    return 0;
}