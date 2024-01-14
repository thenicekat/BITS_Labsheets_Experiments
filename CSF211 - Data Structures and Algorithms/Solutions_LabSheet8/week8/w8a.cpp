#include <bits/stdc++.h>

using namespace std;

const int M = 26;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> freq(n, vector<int> (M));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char &c : s)
            freq[i][c - 'a']++;
    }
    sort(freq.begin(), freq.end());
    
    int ans = 0;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n and freq[j] == freq[i])
            j++;
        ans += (j - i) * (j - i - 1) / 2;
        i = j;
    }

    cout << ans << "\n";

    return 0;
}