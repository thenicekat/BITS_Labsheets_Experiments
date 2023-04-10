// We have input as
// 6 4 1
// 3 3 3 4 4 2
// here subarray size is 4, and we need the max number which has 1 element
// so we keep looping in sliding window format and try to cope

#include <iostream>
#include <map>
#include <stack>
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

        // int max = -1;
        stack<int> prevNumberStore;
        prevNumberStore.push(-1);

        // Converting first window
        for (int i = 0; i < windowSize; i++)
        {

            store[input[i]]++;

            if (store[input[i]] == elem)
            {
                if (!prevNumberStore.empty() && input[i] > prevNumberStore.top())
                {
                    prevNumberStore.push(input[i]);
                }
            }

            if (!prevNumberStore.empty() && prevNumberStore.top() == input[i] && store[input[i]] != elem)
            {
                prevNumberStore.pop();
            }
        }

        cout << prevNumberStore.top() << endl;

        for (int i = windowSize; i < length; i++)
        {
            // 1. remove last element
            // check if the count becomes elem
            store[input[i - windowSize]]--;
            if (!prevNumberStore.empty() && store[input[i - windowSize]] == elem && input[i - windowSize] > prevNumberStore.top())
            {
                prevNumberStore.push(input[i - windowSize]);
            }
            // check if it changes from elem
            if (!prevNumberStore.empty() && prevNumberStore.top() == input[i - windowSize] && store[input[i - windowSize]] != elem)
            {
                prevNumberStore.pop();
            }

            // 2. add new element
            // check if the count becomes elem
            store[input[i]]++;
            if (!prevNumberStore.empty() && input[i] > prevNumberStore.top() && store[input[i]] == elem)
            {
                prevNumberStore.push(input[i]);
            }
            // check if it changes from elem
            if (!prevNumberStore.empty() && prevNumberStore.top() == input[i] && store[input[i]] != elem)
            {
                prevNumberStore.pop();
            }

            cout << prevNumberStore.top() << endl;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}