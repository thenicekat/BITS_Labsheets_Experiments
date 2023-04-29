#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    deque<int> dq;
    for (int i = 0; i < k - 1; ++i)
    {
        while (!dq.empty() and a[i] > a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k - 1; i < n; ++i)
    {
        while (!dq.empty() and a[i] > a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        cout << a[dq.front()] << " ";
        if (dq.front() == i - k + 1)
            dq.pop_front();
    }
    cout << "\n";

    return 0;
}