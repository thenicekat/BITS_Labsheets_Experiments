// https://www.youtube.com/watch?v=_RtghJnM1Qo

// Using stack, you can find the lowest number before it and the lowest number after it
// Using these two, you can find area as (next - prev) * height

// https://www.youtube.com/watch?v=_RtghJnM1Qo

#include <iostream>
#include <stack>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    freopen("C.txt", "r", stdin);

    // Taking inputs
    int numberOfInputs;
    cin >> numberOfInputs;

    int array[numberOfInputs];
    for (int i = 0; i < numberOfInputs; i++)
    {
        cin >> array[i];
    }

    // We create a stack and keep track of all the previous smaller elements
    // If we have a higher number, we pop it until we get a smaller number
    stack<int> prev_stack;
    int previous_smallest[numberOfInputs];
    for (int i = 0; i < numberOfInputs; i++)
    {

        while (!prev_stack.empty() && array[prev_stack.top()] >= array[i])
        {
            prev_stack.pop();
        }

        if (prev_stack.empty())
        {
            previous_smallest[i] = -1;
        }
        else
        {
            previous_smallest[i] = prev_stack.top();
        }
        prev_stack.push(i);
    }

    stack<int> next_stack;
    int next_smallest[numberOfInputs];
    for (int i = numberOfInputs - 1; i >= 0; i--)
    {
        while (!next_stack.empty() && array[next_stack.top()] > array[i])
        {
            next_stack.pop();
        }

        if (next_stack.empty())
        {
            next_smallest[i] = numberOfInputs;
        }
        else
        {
            next_smallest[i] = next_stack.top();
        }
        next_stack.push(i);
    }

    int answer = 0;
    for (int i = 0; i < numberOfInputs; i++)
    {
        answer = max(answer, (next_smallest[i] - previous_smallest[i] - 1) * array[i]);
    }
    cout << answer;
}