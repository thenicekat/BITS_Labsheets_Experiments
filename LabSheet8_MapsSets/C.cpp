// Given array 3 5 1 4 6 6
// Index wise 0:3 1:5 2:1 3:4 4:6 5:6
// x is 2 and y is -1
// They want aj - ai = yj - xi
// we can convert this to aj - yj = ai -xi
// we make two arrays -> 
// i < j :)
// (j)  6 3 7 10 11 -> map(3: 1, 6: 1, 7: 1, 10: 1, 11: 1)
// (i) 3 3 -3 -2 -2 -4 -> map(3: 2, -3: 1, -2: 2, -4: 1)

// (j)  3 7 10 11 -> map(3: 1, 6: 0, 7: 1, 10: 1, 11: 1)
// (i) 3 3 -3 -2 -2 -4 -> map(3: 2, -3: 1, -2: 2, -4: 1)

// (j) 7 10 11 -> map(3: 0, 6: 0, 7: 1, 10: 1, 11: 1)
// (i) 3 3 -3 -2 -2 -4 -> map(3: 2, -3: 1, -2: 2, -4: 1)
// these operations would be O(n)
// but the problem here is i should be less than j
// if we see practically, then 2 for j = 2 i = 0, 1
// so how do we loop without n^2

// we need to see how we can loop without n^2

// we can first loop through j and store in map(3: 2, 6: 1, 7: 1, 10: 1, 11: 1)
// then for every i, we remove the current element from map, and use that logic


#include <iostream>
#include <map>
using namespace std;

int main()
{
    freopen("Inputs/C.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int num;
        cin >> num;

        int input[num];
        for (int i = 0; i < num; i++)
            cin >> input[i];

        int x, y;
        cin >> x >> y;
        
        // This is the aj - yj array
        int inputy[num];
        for (int j = 0; j < num; j++)
        {
            inputy[j] = input[j] - y*j;
        }

        // This is the ai - xi array
        int inputx[num];
        for (int i = 0; i < num; i++)
        {
            inputx[i] = input[i] - x*i;
        }

        int answer = 0;

        // we need pairs such that i < j
        // so we make map of j
        map<int, int> store;
        for(auto x: inputy) store[x]++;

        for(int i = 0; i< num; i++){
            // Remove i element from the map which corresponds to y
            store[inputy[i]]--;

            // Then check the map for the element
            answer += store[inputx[i]];
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}