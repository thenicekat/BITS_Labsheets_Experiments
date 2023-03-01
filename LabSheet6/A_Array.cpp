// The idea seems to be just plain implementation of stack
// Problem is have to get minimum number also in O(1)
// I thought we could maybe keep track of the minimum number using an int
// But we cannot do that because when we pop, we do not know what is happening
// My second idea would be to keep track of minimums in a separate array
#include <iostream>
using namespace std;

class MinStack
{
private:
    int stack[1000000];
    int minArray[1000000];
    int stackTracker;
    int minTracker;

public:
    MinStack()
    {
        stackTracker = -1;
        minTracker = -1;
    }

    int top()
    {
        if (stackTracker == -1)
        {
            return -1;
        }
        else
        {
            return stack[stackTracker];
        }
    }

    int getMin()
    {
        if (minTracker == -1)
        {
            return -1;
        }
        else
        {
            return minArray[minTracker];
        }
    }

    void push(int val)
    {
        if (minTracker == -1)
        {
            minTracker++;
            minArray[minTracker] = val;
        }
        else
        {
            if (val < this->getMin())
            {
                minTracker++;
                minArray[minTracker] = val;
            }
            else
            {
                minArray[minTracker+1] = this->getMin();
                minTracker++;
                // Note: here we do ++ afterwards becauswe getMin depends on minTracker
            }
        }

        stack[++stackTracker] = val;
    }

    void pop()
    {
        if (stackTracker == -1)
        {
            return;
        }
        else
        {
            stackTracker--;
            minTracker--;
        }
    }

    void display(){
        cout << "Stack: ";
        for(int i=0; i<stackTracker + 1; i++){
            cout << stack[i] << "->";
        }
        cout << "|\n";
        cout << "Min Array:";
        for(int i=0; i<stackTracker + 1; i++){
            cout << minArray[i] << "->";
        }
        cout << "|\n";
    }
};

int main()
{
    freopen("A.txt", "r", stdin);

    int numberOfInputs;
    cin >> numberOfInputs;

    MinStack *minStack = new MinStack();

    for (int i = 0; i < numberOfInputs; i++)
    {
        int temp;
        cin >> temp;
        minStack->push(temp);
    }

    int numberOfOperations;
    cin >> numberOfOperations;

    while (numberOfOperations--)
    {
        int operation;
        cin >> operation;

        if (operation == 1)
        {
            int temp;
            cin >> temp;
            minStack->push(temp);
        }
        else if (operation == 2)
        {
            minStack->pop();
        }
        else if (operation == 3)
        {
            cout << minStack->top() << endl;
        }
        else if (operation == 4)
        {
            cout << minStack->getMin() << endl;
        }

    }
    return 0;
}