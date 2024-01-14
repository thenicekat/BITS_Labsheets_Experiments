// The asked time complexity if O(qlogq)
// for every 1 query, we make a map and add it to the map which makes it logq
// and for every 2/3 query it becomes logq again if we use upper_bound or lower_bound functions
// so approx -> qlogq

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/D.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int max;
        cin >> max;

        int queries;
        cin >> queries;

        // We create a dictionary
        map<int, int> dict;

        for (int i = 0; i < queries; i++)
        {
            int type, k;
            cin >> type >> k;

            // Debugging:
            // cout << "----------------------" << endl;
            // for(auto m: dict){
            //     cout << "::>" << m.first << " " << m.second << endl;
            // }
            // cout << "----------------------" << endl;
            // cout << type << " " << k << endl;

            // If type = 1, either add or remove from dict in logn
            if (type == 1)
            {
                if (dict.find(k) == dict.end())
                {
                    dict[k] = 1;
                }
                else
                {
                    if (dict[k] == 1)
                        dict.erase(k);
                }
            }
            // if type = 2, we need to find the upper bound
            else if (type == 2)
            {
                if (dict.lower_bound(k) == dict.end())
                {
                    cout << -1 << endl;
                }
                else
                {
                    cout << dict.lower_bound(k)->first << endl;
                }
            }
            // if type = 3, we need to find the first element smaller than the lower bound
            // so the x-- extra comes
            else if (type == 3)
            {
                auto x = dict.upper_bound(k);
                if(x != dict.begin()){
                    x--;
                    if ((x) == dict.end())
                    {
                        cout << -1 << endl;
                    }
                    else
                    {
                        cout << (x)->first << endl;
                    }
                }else{
                    cout << -1 << endl;
                }
                
            }
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}