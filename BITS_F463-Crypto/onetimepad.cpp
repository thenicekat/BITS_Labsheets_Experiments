// Implementation of One Time Pad
#include <bits/stdc++.h>
#define endl "\n"
#define int long long int

using namespace std;

int32_t main()
{
    // cin.tie(0)->sync_with_stdio(0);
    cout << "-------------Encrypting-------------" << endl;
    cout << "Enter the binary number you want to send: ";
    string input;
    cin >> input;

    string key;
    string output;
    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i] - '0';

        int curr_key = rand() % 2;
        key += curr_key + '0';

        int curr_out = curr ^ curr_key;
        output += curr_out + '0';
    }

    cout << "Please share the following key: " << key << endl;
    cout << "Encrypted Binary: " << output << endl;

    cout << "-------------Decrypting-------------" << endl;
    string re_input;
    for (int i = 0; i < input.size(); i++)
    {
        int curr = output[i] - '0';

        int curr_out = curr ^ (key[i] - '0');
        re_input += curr_out + '0';
    }
    cout << "Decrypted Binary: " << re_input << endl;
}