// We have n rooms numbered from 0 to n-1 - Basically an array
// We have to find the next room with number less than the current room
// Using stack mostly

// Okay, we used the nearest greater and smaller number concept in the
// C question I think

// Input:
//  5
//  0 1 2 3 4
//  1 -2 3 4 3

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    freopen("B.txt", "r", stdin);

    int numberOfInputs;
    cin >> numberOfInputs;

    int array[numberOfInputs];
    for (int i = 0; i < numberOfInputs; i++)
        cin >> array[i];

    stack<int> next_stack;
    int next_greatest[numberOfInputs];
    for (int i = 2 * numberOfInputs - 1; i >= 0; i--)
    {
        while (!next_stack.empty() && array[next_stack.top()] <= array[i % numberOfInputs])
        {
            next_stack.pop();
        }

        if (i < numberOfInputs)
        {
            if (next_stack.empty())
            {
                next_greatest[i] = -1;
            }
            else
            {
                next_greatest[i] = next_stack.top();
            }
        }
        next_stack.push(i % numberOfInputs);
    }

    for (int i = 0; i < numberOfInputs; i++)
    {
        if (next_greatest[i] == -1)
        {
            cout << -1 << " ";
        }
        else if (next_greatest[i] < i)
        {
            cout << next_greatest[i] - i + numberOfInputs << " ";
        }
        else
            cout << next_greatest[i] - i << " ";
    }

    return 0;
}
