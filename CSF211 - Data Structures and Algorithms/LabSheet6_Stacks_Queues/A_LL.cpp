// The idea seems to be just plain implementation of stack
// Problem is have to get minimum number also in O(1)
// I thought we could maybe keep track of the minimum number using an int
// But we cannot do that because when we pop, we do not know what is happening
// My second idea would be to keep track of minimums in a separate array
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        this->data = n;
        this->next = nullptr;
    }
};

class MinStack
{
private:
    Node *stackTop;
    Node *min;

public:
    MinStack()
    {
        stackTop = nullptr;
        min = nullptr;
    }

    int top()
    {
        if (stackTop == nullptr)
        {
            return -1;
        }
        else
        {
            return stackTop->data;
        }
    }

    int getMin()
    {
        if (min == nullptr)
        {
            return -1;
        }
        else
        {
            return min->data;
        }
    }

    void push(int val)
    {
        Node *newNode = new Node(val);

        if (min == nullptr)
        {
            min = newNode;
        }
        else
        {
            if (val < this->getMin())
            {
                Node *minNewNode = new Node(val);
                minNewNode->next = min;
                min = minNewNode;
            }
            else
            {
                Node *minNewNode = new Node(this->getMin());
                minNewNode->next = min;
                min = minNewNode;
            }
        }

        if (stackTop == nullptr)
        {
            stackTop = newNode;
        }
        else
        {
            newNode->next = stackTop;
            stackTop = newNode;
        }
    }

    void pop()
    {
        if (stackTop == nullptr)
        {
            return;
        }
        else
        {
            Node *temp = stackTop;
            stackTop = stackTop->next;
            free(temp);

            Node *tempMin = min;
            min = min->next;
            free(tempMin);
        }
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
            cout << "::>" << minStack->top() << endl;
        }
        else if (operation == 4)
        {
            cout << "::>" << minStack->getMin() << endl;
        }
    }
    return 0;
}