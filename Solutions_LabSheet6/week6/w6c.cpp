#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int nxt[n];
    for (int i = 0; i < n; ++i)
        nxt[i] = n;
    stack<int> st;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() and a[st.top()] >= a[i])
            st.pop();
        if (!st.empty())
            nxt[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() and a[st.top()] >= a[i])
            st.pop();
        int prev = st.empty() ? -1 : st.top();
        ans = max(ans, (nxt[i] - prev - 1) * a[i]);
        st.push(i);
        cout << i << " " << nxt[i] << " " << prev << endl;
    }
    cout << ans << "\n";

    return 0;
}