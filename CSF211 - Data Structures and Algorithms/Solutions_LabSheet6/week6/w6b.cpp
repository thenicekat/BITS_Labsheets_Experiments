#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    int nxtg[n];
    for (int i = 0; i < n; ++i)
        nxtg[i] = n;
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!st.empty() and a[st.top()] <= a[i % n])
            st.pop();
        if (!st.empty())
            nxtg[i % n] = st.top();
        st.push(i % n);
    }
    for (int i = 0; i < n; ++i) {
        if (nxtg[i] == n) cout << -1 << " ";
        else cout << (nxtg[i] - i + n) % n << " ";
    }
    cout << "\n";

    return 0;
}