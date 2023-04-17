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
            store[input[i]]++;
        }

        int answer = 0;

        for (auto x : store)
        {
            for(int i=0; i<x.second; i++){
                auto iterator = store.upper_bound(x.first + remK - 1);
                if (iterator != store.end())
                {
                    cout << x.first << " -> " << (*iterator).first << endl;

                    if(store[(*iterator).first] == 1) store.erase(iterator);
                    else store[(*iterator).first]--;

                    answer++;
                }
            }
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}