#include <bits/stdc++.h>
using namespace std;

int customGCD(int a, int b)
{
    if (b == 0)
        return a;
    cout << a << " = " << b << " * " << a / b << " + " << int(a % b) << endl;
    return customGCD(b, a % b);
}

int main()
{
    freopen("gcd.txt", "r", stdin);
    int counter;
    cin >> counter;
    cout << "Euclidean Algorithm for GCD" << endl;
    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        int a, b;
        cin >> a >> b;

        cout << customGCD(a, b) << endl;
        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}