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

        // Am not entirely sure of this but let's see
        // this will be nlogn
        priority_queue<int, vector<int>, greater<int>> store;
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                int x;
                cin >> x;
                store.push(x);
            }
        }

        // this will be klogn
        for(int i=0; i<k-1; i++){
            store.pop();
        }

        // this will be O(1)
        cout << store.top() << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}