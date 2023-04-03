// Given array 3 5 1 4 6 6
// Index wise 0:3 1:5 2:1 3:4 4:6 5:6
// x is 2 and y is -1
// They want aj - ai = yj - xi
// we can convert this to aj - yj = ai -xi
// we make two arrays -> 3 6 3 7 10 11 -> map (3: 2, 6: 1, 7: 1, 10: 1, 11: 1)
// second array will be -> 3 3 -3 -2 -2 -4 (3: 2, -3: 1, -2: 2, -4: 1)
// these operations would be O(n)
// after this we can use two maps and add to the map
// in cpp map is O(logn)
// so we get nlogn operations to check if any is in both elements then we can
// multiply and add

#include <iostream>
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

        int inputy[num];
        for (int i = 0; i < num; i++)
        {
            inputy[i] = input[i] - y*i;
        }

        int inputx[num];
        for (int i = 0; i < num; i++)
        {
            inputx[i] = input[i] - x*i;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}