// We have input as
// 6 4 1
// 3 3 3 4 4 2
// here subarray size is 4, and we need the max number which has 1 element
// so we keep looping in sliding window format and try to cope

#include <iostream>
#include <map>
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

        int max = -1;

        // Converting first window
        for (int i = 0; i < windowSize; i++)
        {
            if (store.find(input[i]) != store.end())
            {
                store[input[i]]++;
            }
            else
            {
                store[input[i]] = 1;
            }

            if (store[input[i]] == elem)
            {
                if (input[i] > max)
                {
                    max = input[i];
                }
            }

            if (max == input[i] && store[input[i]] > elem)
            {
                max = -1;
            }
        }

        cout << max << endl;

        for (int i = windowSize; i < length; i++)
        {
            // remove element
            store[input[i - windowSize]]--;
            if (store[input[i - windowSize]] && input[i - windowSize] > max)
            {
                max = input[i - windowSize];
            }

            // add element
            if (store.find(input[i]) != store.end())
            {
                store[input[i]]++;
            }
            else
            {
                store[input[i]] = 1;
            }

            if (store[input[i]] == elem)
            {
                if (input[i] > max)
                {
                    max = input[i];
                }
            }

            if (max == input[i] && store[input[i]] > elem)
            {
                max = -1;
            }

            cout << max << endl;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}