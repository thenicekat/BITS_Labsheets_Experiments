// Implementation of caesar cipher
#include <bits/stdc++.h>
#define endl "\n"
#define int long long int

using namespace std;

int32_t main()
{
    int max = 'z';

    cout << "Enter String: ";
    string input;
    cin >> input;

    cout << "Enter key (0-25): ";
    int key;
    cin >> key;

    string output;
    for (int i = 0; i < input.size(); i++)
    {
        int x = (input[i] + key) % max;
        cout << (int)input[i] << " + " << key << " => " << x << endl;
        output += (char)x;
    }
    cout << "Encrypted String: " << output << endl;
}