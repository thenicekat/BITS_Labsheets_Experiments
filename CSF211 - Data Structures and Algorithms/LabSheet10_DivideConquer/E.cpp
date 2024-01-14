// Sort by height and width
// then go one by one and maybe kadane's algo

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    // We sort them such that 6, 7 comes before 6, 4 and this is because
    // 6, 7 we can put more dolls inside
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    freopen("Inputs/E.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take Input
        int inLen;
        cin >> inLen;
        pair<int, int> input[inLen];
        for (int i = 0; i < inLen; i++)
        {
            int x, y;
            cin >> x >> y;
            input[i] = {x, y};
        }

        // Sort them using a compare function - nlogn
        sort(input, input + inLen, comp);

        for(auto x: input){
                cout << x.first << " " << x.second << endl;
            }

        vector<int> store;

        // Then we do LIS on height
        for (int i = 0; i < inLen; i++)
        {
            if (lower_bound(store.begin(), store.end(), input[i].second) != store.end())
            {
                store[lower_bound(store.begin(), store.end(), input[i].second) - store.begin()] = input[i].second;
            }
            else
            {
                store.push_back(input[i].second);
            }
        }

        cout << store.size() << endl;
    }

    cout << "--------- END TEST CASE "
         << " ---------" << endl;
}