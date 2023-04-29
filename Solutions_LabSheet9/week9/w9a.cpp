#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    
    multiset<int> ms;
    long long sum = 0;

    for (auto &x : a) {
        sum += x;
        ms.insert(x);
        while (sum < 0) {
            sum -= *ms.begin();
            ms.erase(ms.begin());
        }
    }

    cout << ms.size() << "\n";


    return 0;
}