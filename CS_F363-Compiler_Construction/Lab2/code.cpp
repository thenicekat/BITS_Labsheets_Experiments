#include <bits/stdc++.h>
using namespace std;

enum OP
{
    CONCAT,
    OR,
    KLEENE_STAR
};

class State
{
public:
    int number;
    vector<State *> a;
    vector<State *> b;
    vector<State *> e;

    State()
    {
        a = {};
        b = {};
        e = {};
    }
};

class StateSet
{
public:
    State *start;
    State *end;

    StateSet()
    {
        start = new State();
        end = new State();
    }

    StateSet(char x)
    {
        start = new State();
        end = new State();
        if (x == 'a')
            start->a.push_back(end);
        if (x == 'b')
            start->b.push_back(end);
    }

    void makeOR(StateSet *first, StateSet *second)
    {
        // Make the Start -> first -> end loop
        start->e.push_back(first->start);
        first->end->e.push_back(end);

        // Make the Start -> second -> end loop
        start->e.push_back(second->start);
        second->end->e.push_back(end);
    }
};

State *startState = new State();

// Function to return precedence of operators
int prec(char c)
{
    if (c == '*')
        return 3;
    else if (c == '.')
        return 2;
    else if (c == '|')
        return 1;
    else
        return -1;
}

// Function to convert infix to Post fix
string infixToPostfix(string input)
{
    string postfix;

    stack<char> s;
    for (auto x : input)
    {
        // If character is operator print
        if (('a' <= x && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
        {
            postfix += x;
        }
        else if (x == '(')
            s.push(x);
        else if (x == ')')
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && prec(x) < prec(s.top()) ||
                   !s.empty() && prec(x) == prec(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(x);
        }
    }

    // Pop all the remaining elements from the stack
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    // Return the postfix expression
    return postfix;
}

void createNFA(string postfix)
{
    stack<StateSet *> s;
    for (auto x : postfix)
    {
        if (x == 'a' || x == 'b')
            s.push(new StateSet(x));
        else if (x == '|')
        {
            StateSet *first = s.top();
            s.pop();
            StateSet *second = s.top();
            s.pop();
            StateSet *final = new StateSet();
            final->makeOR(first, second);
            s.push(final);
        }
    }
}

bool runTheModel(string regexp, string testcase)
{
    cout << "Reg Exp. " << regexp << endl;
    cout << "Testcase: " << testcase << endl;

    // Step 1: Convert infix to Postfix
    string postfix = infixToPostfix(regexp);
    cout << "Postfix: " << postfix << endl;

    // Step 2:
    createNFA(postfix);

    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        string re;
        string input;
        cin >> re >> input;

        if (runTheModel(re, input))
        {
            cout << "Output: YES" << endl;
        }
        else
        {
            cout << "Output: NO" << endl;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl
             << endl;
    }
}