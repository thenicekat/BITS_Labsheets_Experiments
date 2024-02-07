// The purpose of this code is to give a list of vertices which count as the convex hull for the list of vertices

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("convexhull.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        int numberOfInputs;
        cin >> numberOfInputs;

        vector<pair<int, int>> coords(numberOfInputs);
        for (int i = 0; i < numberOfInputs; i++)
        {
            cin >> coords[i].first >> coords[i].s
        }

        cout
            << "--------- END TEST CASE "
            << " ---------" << endl;
    }
}