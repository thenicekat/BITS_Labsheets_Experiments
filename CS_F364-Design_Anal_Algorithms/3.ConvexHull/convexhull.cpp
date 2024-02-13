// The purpose of this code is to give a list of vertices which count as the convex hull for the list of vertices

#include <bits/stdc++.h>
using namespace std;

void upperhull(pair<int, int> pmin, pair<int, int> pmax, set<pair<int, int>> vertices)
{
}

int main()
{
    freopen("convexhull_input.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        // Reading input - O(n)
        int numberOfInputs;
        cin >> numberOfInputs;
        cout << "::> Reading " << numberOfInputs << " number of coordinates." << endl;
        vector<pair<int, int>> coords(numberOfInputs);
        for (int i = 0; i < numberOfInputs; i++)
        {
            cin >> coords[i].first >> coords[i].second;
        }

        // Find points of least and max x coordinate - O(n)
        cout << "::> Finding points with least x coordinate and max x coordinate." << endl;
        pair<int, int> pmin = coords[0];
        pair<int, int> pmax = coords[0];
        for (auto coord : coords)
        {
            // Check min x coord
            if (coord.first < pmin.first)
            {
                pmin = coord;
            }
            // if x same take the one with highest y coordinate
            if (coord.first == pmin.first && coord.second > pmin.second)
            {
                pmin = coord;
            }

            // Check max x coord
            if (coord.first > pmax.first)
            {
                pmax = coord;
            }
            // if x same take the one with highest y coordinate
            if (coord.first == pmax.first && coord.second > pmin.second)
            {
                pmax = coord;
            }
        }
        cout << "::> P_min: " << pmin.first << ',' << pmin.second << endl;
        cout << "::> P_max: " << pmax.first << ',' << pmax.second << endl;

        cout << "::> Set T - which contains all the points between x(pmin) and x(pmax)" << endl;
        set<pair<int, int>> T;
        for (auto coord : coords)
        {
            if (pmin.first < coord.first && coord.first < pmax.first)
            {
                T.insert(coord);
            }
        }
        upperhull(pmin, pmax, T);

        cout
            << "--------- END TEST CASE "
            << " ---------" << endl;
    }
}