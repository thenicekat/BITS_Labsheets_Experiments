// For every point, no of ways to choose other 2 points is that
// total ways of choosing 2 - ways of choosing 2 such that one of them has same slope as the initial selected point
// 4
// 0 0
// 0 2
// 2 0
// 2 2

// 0, 0 map => ((0, 2) infinity, (2, 0) 0, )

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    freopen("Inputs/G.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int numberOfPoints;
        cin >> numberOfPoints;

        pair<int, int> points[numberOfPoints];
        for (int i = 0; i < numberOfPoints; i++)
        {
            int x, y;
            cin >> x >> y;
            points[i] = {x, y};
        }

        int answer = 0;

        // loop through all points
        for (int i = 0; i < numberOfPoints; i++)
        {
            // Create a map to store slopes
            map<pair<int, int>, int> store;

            // loop through all next points
            for(int j = i+1; j<numberOfPoints; j++){
                int X = points[i].first - points[j].first;
                int Y = points[i].second - points[j].second;

                // We find gcd because we need least form of slope
                // say we have X = 4 and y = 2 -> GCD = 2 -> X = 2 and Y = 1
                int g = __gcd(X, Y);   
                X /= g;
                Y /= g;

                // And basically in the map, we store slopes and their counters
                store[{ X, Y }]++;
            }

            // Now to find number of triangles, we first add to answer, 
            // total number of ways of selecting two points
            int temp = numberOfPoints - (i + 1);
            // We subtract i+1 because, for a point at index 2, we only count the above points not the points before it
            answer += temp * (temp - 1)/2;

            // Now we need to remove those triangles where area is 0
            // i.e we need to subtract those cases where we choose 2 points with same slope with respect to the point chosen
            for(auto m: store){
                answer -= (m.second)*(m.second - 1)/2;
            }

        }
        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}