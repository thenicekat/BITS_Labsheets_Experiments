#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

// GLOBAL VARIABLES
int stateCounter = 0;

class State
{
public:
    int number;
    vector<State *> a;
    vector<State *> b;
    vector<State *> e;

    State()
    {
        number = stateCounter++;
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
        this->start = new State();
        this->end = new State();
    }

    StateSet(char x)
    {
        this->start = new State();
        this->end = new State();
        if (x == 'a')
            this->start->a.push_back(this->end);
        if (x == 'b')
            this->start->b.push_back(this->end);
    }

    void OR(StateSet *first, StateSet *second)
    {
        // Make the Start -> first -> end loop
        this->start->e.push_back(first->start);
        first->end->e.push_back(this->end);

        // Make the Start -> second -> end loop
        this->start->e.push_back(second->start);
        second->end->e.push_back(this->end);
    }

    void CONCAT(StateSet *first, StateSet *second)
    {
        // Make the Start -> first
        this->start->e.push_back(first->start);
        // first -> second
        first->end->e.push_back(second->start);
        // second -> end
        second->end->e.push_back(this->end);
    }

    void KLEENESTAR(StateSet *top)
    {
        // Start -> top.start
        this->start->e.push_back(top->start);
        // top.end -> start
        top->end->e.push_back(this->start);
        // start -> end
        this->start->e.push_back(this->end);
    }

    map<int, vector<vector<int>>> performBFS()
    {
        // Map to keep track of all transitions
        map<int, vector<vector<int>>> stateTransitions;
        // Used to perform BFS and keep track of repetitive states
        queue<State *> q;
        map<int, int> mp;

        q.push(this->start);
        mp[this->start->number] = 1;

        while (!q.empty())
        {
            State *curr = q.front();
            q.pop();

            mp[curr->number] = 1;

            // cout << "::> State Number: " << curr->number << endl;
            // Initialize, corresponding to a | b | e
            stateTransitions[curr->number] = {{}, {}, {}};

            for (auto x : curr->a)
            {
                stateTransitions[curr->number][0].push_back(x->number);
                if (!mp[x->number])
                    q.push(x);
            }
            for (auto x : curr->b)
            {
                stateTransitions[curr->number][1].push_back(x->number);
                if (!mp[x->number])
                    q.push(x);
            }
            for (auto x : curr->e)
            {
                stateTransitions[curr->number][2].push_back(x->number);
                if (!mp[x->number])
                    q.push(x);
            }
        }

        return stateTransitions;
    }
};

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
            while (!s.empty() && prec(x) < prec(s.top()) || !s.empty() && prec(x) == prec(s.top()))
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

StateSet *createNFA(string postfix)
{
    stack<StateSet *> s;
    for (auto x : postfix)
    {
        if (x == 'a' || x == 'b')
            s.push(new StateSet(x));
        else if (x == '|')
        {
            cout << "::> Found an OR" << endl;
            StateSet *first = s.top();
            s.pop();
            StateSet *second = s.top();
            s.pop();
            StateSet *final = new StateSet();
            final->OR(first, second);
            s.push(final);
        }
        else if (x == '.')
        {
            cout << "::> Found a CONCAT" << endl;
            StateSet *first = s.top();
            s.pop();
            StateSet *second = s.top();
            s.pop();
            StateSet *final = new StateSet();
            final->CONCAT(second, first);
            s.push(final);
        }
        else if (x == '*')
        {
            cout << "::> Found a KLEENE STAR" << endl;
            StateSet *top = s.top();
            s.pop();
            StateSet *final = new StateSet();
            final->KLEENESTAR(top);
            s.push(final);
        }
    }

    if (s.empty() || s.size() > 1)
    {
        cout << "ERROR OCCURRED: Found " << s.size() << " elements." << endl;
        return nullptr;
    }
    else
    {
        return s.top();
    }
}

void printSet(set<int> currentSet)
{
    cout << "[ ";
    for (auto x : currentSet)
    {
        cout << x << ' ';
    }
    cout << "]";
}

map<char, vector<char>> convertNFAtoDFA(map<char, int> &finalStates, map<int, vector<vector<int>>> stateTransitions)
{
    // We need to somehow get all epsilon closures
    cout << endl
         << "::> Epsilon Closures: " << endl;

    vector<vector<int>> epsilonClosures;
    for (int i = 0; i < stateTransitions.size(); i++)
    {
        vector<int> perState;
        cout << "::> State: " << i << " ";
        // Map to keep track of visited states
        map<int, int> mp;
        // Queue for all possible states
        queue<int> tq;
        for (auto x : stateTransitions[i][2])
        {
            tq.push(x);
        }
        while (!tq.empty())
        {
            int currState = tq.front();
            tq.pop();
            mp[currState] = 1;

            for (auto x : stateTransitions[currState][2])
            {
                if (!mp[x])
                {
                    tq.push(x);
                }
            }
        }

        cout << "{ ";
        for (auto x : mp)
        {
            cout << x.first << ' ';
            perState.push_back(x.first);
        }
        cout << "} ";
        cout << endl;
        epsilonClosures.push_back(perState);
    }

    queue<set<int>> q;
    map<set<int>, int> mapOfStatesVisited;

    char stateLetter = 'A';
    q.push({0});
    mapOfStatesVisited[{0}] = stateLetter++;

    map<char, vector<char>> theResultantDFA;

    cout << endl
         << "::> Found the following DFA:" << endl;

    while (!q.empty())
    {
        set<int> currentSet = q.front();
        q.pop();

        set<int>
            nextSet0, nextSet1;
        for (auto x : currentSet)
        {
            for (auto y : stateTransitions[x][0])
            {
                nextSet0.insert(y);
                for (auto z : epsilonClosures[y])
                {
                    nextSet0.insert(z);
                }
            }
            for (auto y : stateTransitions[x][1])
            {
                nextSet1.insert(y);
                for (auto z : epsilonClosures[y])
                {
                    nextSet1.insert(z);
                }
            }
        }

        if (mapOfStatesVisited.find(nextSet0) == mapOfStatesVisited.end())
        {
            q.push(nextSet0);
            mapOfStatesVisited[nextSet0] = stateLetter++;
        }
        if (mapOfStatesVisited.find(nextSet1) == mapOfStatesVisited.end())
        {
            q.push(nextSet1);
            mapOfStatesVisited[nextSet1] = stateLetter++;
        }

        // Printing the DFA
        // printSet(currentSet);
        // cout << " ";
        // printSet(nextSet0);
        // cout << " ";
        // printSet(nextSet1);
        // cout << endl;

        theResultantDFA[(char)mapOfStatesVisited[currentSet]] = {
            (char)mapOfStatesVisited[nextSet0],
            (char)mapOfStatesVisited[nextSet1]};
    }

    for (auto x : mapOfStatesVisited)
    {
        int isFinalState = 0;
        for (auto v : x.first)
        {
            if (v == stateCounter - 1)
            {
                isFinalState = 1;
            }
        }

        if (isFinalState)
        {
            finalStates[(char)mapOfStatesVisited[x.first]] = 1;
        }
    }

    return theResultantDFA;
}

bool runStringOnDFA(string input, map<char, int> finalStates, map<char, vector<char>> theResultantDFA)
{
    // Print the DFA
    for (auto x : theResultantDFA)
    {
        cout << x.first << ' ';
        for (auto y : theResultantDFA[x.first])
        {
            cout << y << ' ';
        }
        cout << endl;
    }
    char currentState = 'A';
    cout << "::> Flow: ";
    for (int i = 0; i < input.length(); i++)
    {
        cout << "->" << currentState;
        int currentChar = input[i] - 'a';
        currentState = theResultantDFA[currentState][currentChar];
    }
    cout << "->" << currentState;
    cout << endl;

    if (finalStates[currentState])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool runTheModel(string regexp, string testcase)
{
    cout << "Reg Exp. " << regexp << endl;
    cout << "Testcase: " << testcase << endl;

    // Step 1: Convert infix to Postfix
    string postfix = infixToPostfix(regexp);
    cout << "Postfix: " << postfix << endl;

    // Step 2: Generate the State Set Structure
    StateSet *output = createNFA(postfix);

    // Step 3: Perform BFS on this structure
    map<int, vector<vector<int>>> stateTransitions = output->performBFS();

    // Step 4: Print the NFA with e transitions
    cout << "::> Found the following NFA with e Transitions: " << endl;
    for (int i = 0; i < stateTransitions.size(); i++)
    {
        cout << "::> State: " << i << " ";
        for (auto x : stateTransitions[i])
        {
            cout << "{ ";
            for (auto y : x)
            {
                cout << y << ' ';
            }
            cout << "} ";
        }
        cout << endl;
    }

    // Step 5: Convert NFA to DFA
    map<char, int> finalStates;
    map<char, vector<char>>
        theResultantDFA = convertNFAtoDFA(finalStates, stateTransitions);

    // Step 6: Run string on DFA
    bool res = runStringOnDFA(testcase, finalStates, theResultantDFA);

    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "--------------------- TEST CASE " << m + 1 << " -----------------------" << endl;

        // Input parameters
        string regex, input;
        cin >> regex >> input;

        // We have to add a . everytime we see a )(
        for (int i = 1; i < regex.size(); i++)
        {
            if (regex[i] == '(' && regex[i - 1] == ')')
            {
                regex = regex.substr(0, i) + "." + regex.substr(i, regex.size() - i);
            }
        }

        if (runTheModel(regex, input))
        {
            cout << "Output: YES" << endl;
        }
        else
        {
            cout << "Output: NO" << endl;
        }

        cout << "::> Resetting State numbers" << endl;
        stateCounter = 0;
        cout << "--------------------- END TEST CASE "
             << " ---------------------" << endl
             << endl;
    }
}