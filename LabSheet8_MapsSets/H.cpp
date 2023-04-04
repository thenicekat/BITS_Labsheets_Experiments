// A map of strings would be fine enough?
// using sliding window to update the map
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

int main()
{
    freopen("Inputs/H.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take input - O(n)
        string key;
        cin >> key;
        cout << "Input: " << key << endl;

        // Create an ordered map
        map<string, int> store;

        for (int i = 0; i < key.size() - 10; i++)
        {
            string mapKey = "";
            // Loop to generate key O(10)
            for (int j = i; j < i + 10; j++)
            {
                mapKey += key[j];
            }

            // Put in map logn
            if (store.find(mapKey) == store.end())
            {
                store[mapKey] = 1;
            }
            else
            {
                store[mapKey]++;
            }
        }
        // The above loop goes n times -> nlogn + 10n

        // Now we need to iterate again through the map
        // Time Complexity will be O(n / 10)
        int answer = 0;
        for(auto x: store){
            if(x.second > 1){
                answer++;
            }
        }
        cout << answer << endl;
        for(auto x: store){
            if(x.second > 1){
                cout << x.first << endl;
            }
        }

        // Total TC = nlogn + 10n + 2n => nlogn :)

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}