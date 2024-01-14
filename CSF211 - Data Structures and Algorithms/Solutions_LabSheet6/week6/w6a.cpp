#include <iostream>
using namespace std;

const int N = 1e6 + 5;

class Stack
{
    int size = 0;
    int elements[N];

public:
    void push(int val)
    {
        elements[size] = val;
        size++;
    }
    void pop()
    {
        size--;
    }
    int top()
    {
        return elements[size - 1];
    }
    bool empty()
    {
        return size == 0;
    }
};

class MinStack
{
    Stack st1, st2;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st1.push(val);
        if (st2.empty() or st2.top() >= val)
            st2.push(val);
    }

    void pop()
    {
        if (st2.top() == st1.top())
            st2.pop();
        st1.pop();
    }

    int top()
    {
        return st1.top();
    }

    int getMin()
    {
        return st2.top();
    }
};

int main()
{
    int n;
    cin >> n;
    MinStack ms;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ms.push(x);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            ms.push(x);
        }
        else if (op == 2)
        {
            ms.pop();
        }
        else if (op == 3)
        {
            cout << ms.top() << "\n";
        }
        else
        {
            cout << ms.getMin() << "\n";
        }
    }

    return 0;
}
