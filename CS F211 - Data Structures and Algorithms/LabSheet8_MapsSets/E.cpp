// We have input as
// 6 4 1
// 3 3 3 4 4 2
// here subarray size is 4, and we need the max number which has 1 element
// so we keep looping in sliding window format and try to cope

#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    freopen("Inputs/E.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int length, windowSize, elem;
        cin >> length >> windowSize >> elem;
        int input[length];

        map<int, int> store;

        // Taking input in array O(n)
        for (int i = 0; i < length; i++)
        {
            cin >> input[i];
        }

        set<int> elements;

        // Converting first window
        for (int i = 0; i < windowSize; i++)
        {

            store[input[i]]++;

            if (store[input[i]] == elem)
            {
                elements.insert(input[i]);
            }

            if (store[input[i]] != elem)
            {
                elements.erase(input[i]);
            }
        }

        if (elements.size() != 0)
            cout << *(elements.rbegin()) << endl;
        else
            cout << -1 << endl;

        for (int i = windowSize; i < length; i++)
        {
            // 1. remove last element
            // check if the count becomes elem
            store[input[i - windowSize]]--;
            if (store[input[i - windowSize]] == elem)
            {
                elements.insert(input[i - windowSize]);
            }

            if (store[input[i - windowSize]] != elem)
            {
                elements.erase(input[i - windowSize]);
            }

            // 2. add new element
            // check if the count becomes elem
            store[input[i]]++;
            if (store[input[i]] == elem)
            {
                elements.insert(input[i]);
            }

            if (store[input[i]] != elem)
            {
                elements.erase(input[i]);
            }

            if (elements.size() != 0)
                cout << *(elements.rbegin()) << endl;
            else
                cout << -1 << endl;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}