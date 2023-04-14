// Maybe we can use upper bound and lower bound?

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/F.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inLen, remK;
        cin >> inLen >> remK;

        int input[inLen];
        map<int, int> store;
        for (int i = 0; i < inLen; i++)
        {
            cin >> input[i];
            store[input[i]] = 0;
        }

        int answer = 0;

        for (auto x : store)
        {
            auto iterator = store.upper_bound(x.first + remK - 1);
            if (iterator != store.end())
            {
                cout << x.first << " -> " << (*iterator).first << endl;
                store.erase(iterator);
                answer++;
            }
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}