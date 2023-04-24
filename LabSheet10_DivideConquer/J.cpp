// Legit no idea on what to do
// hm bro it says kth smallest lmao
// so obviously we use min heap or priority queue
// n + k log n

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/J.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int dim, k;
        cin >> dim >> k;
        int input[dim][dim];
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        >   store;

        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                cin >> input[i][j];
            }
        }

        // We push only n so complexity will be nlogn
        for (int i = 0; i < dim; i++)
        {
            store.push({input[0][i], {0, i}});
        }

        // this will be klogn
        for (int i = 0; i < k - 1; i++)
        {
            pair<int, pair<int, int>> cur = store.top();
            store.pop();

            // We push same 
            store.push({input[cur.second.first + 1][cur.second.second], {cur.second.first + 1, cur.second.second}});
        }

        // this will be O(1)
        cout << store.top().first << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}