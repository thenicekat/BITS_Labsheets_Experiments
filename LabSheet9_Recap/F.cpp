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

        map<int, int> store, storeSecondHalf;

        int inLen, remK;
        cin >> inLen >> remK;

        int input[inLen];
        for (int i = 0; i < inLen; i++)
        {
            // Take input
            cin >> input[i];

            if (i < inLen / 2)
            {
                store[input[i]]++;
            }
            else
            {
                storeSecondHalf[input[i]]++;
            }
        }
        
        sort(input, input + inLen);

        int answer = 0;

        for (auto x : store)
        {
            for (int i = 0; i < x.second; i++)
            {
                auto iterator = storeSecondHalf.upper_bound(x.first + remK - 1);
                if (iterator != storeSecondHalf.end())
                {
                    cout << x.first << " -> " << (*iterator).first << endl;

                    if (storeSecondHalf[(*iterator).first] == 1)
                        storeSecondHalf.erase(iterator);
                    else
                        storeSecondHalf[(*iterator).first]--;

                    answer++;
                }
            }
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}