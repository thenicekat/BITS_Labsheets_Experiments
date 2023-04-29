#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string A;
    cin >> A;
    
    if (count(A.begin(), A.end(), '9') == n) {
        cout << 1;
        for (int i = 0; i < n - 1; ++i)
            cout << 0;
        cout << 1 << "\n";
        return 0;
    }

    for (int i = (n - 1) / 2; i >= 0; --i) {
        if (A[i] > A[n - 1 - i]) {
            for (int j = i; j >= 0; --j)
                A[n - 1 - j] = A[j];
            break;
        } else if (A[i] < '9') {
            A[i] = char(A[i] + 1);
            for (int j = i; j >= 0; --j)
                A[n - 1 - j] = A[j];
            break;
        } else {
            A[i] = A[n - 1 - i] = '0';
        }
    }
    cout << A << "\n";



    return 0;
}