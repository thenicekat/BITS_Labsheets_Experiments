#include <bits/stdc++.h>
using namespace std;

map<int, int> finalStates;
map<int, vector<vector<int>>> stateTransitions;

void printSet(set<int> currentSet)
{
    cout << "[ ";
    for (auto x : currentSet)
    {
        cout << x << ' ';
    }
    cout << "]";
}

int main()
{
    freopen("input.txt", "r", stdin);

    string line;

    // Read number of states
    getline(cin, line);
    stringstream ss(line);
    int numberOfStates;
    ss >> numberOfStates;
    cout << "::> Found number of states: " << numberOfStates << endl;

    // Read the final states
    getline(cin, line);
    ss.str(line);
    ss.clear();

    int finalState;
    while (ss >> finalState)
    {
        finalStates[finalState] = 1;
    }
    cout << "::> Found Final States: ";
    for (auto x : finalStates)
    {
        cout << x.first << ' ';
    }
    cout << endl;

    // Read state transitions
    for (int i = 0; i < numberOfStates; i++)
    {
        getline(cin, line);
        ss.str(line);
        ss.clear();

        int index;
        ss >> index;
        stateTransitions[index] = {{}, {}, {}};

        // Now read {a, b}
        char temp;
        int currentIndex = 0;
        while (ss >> temp)
        {
            if (temp == '}')
            {
                currentIndex++;
            }
            if (temp != '}' && temp != '{' && temp != ',')
            {
                stateTransitions[index][currentIndex].push_back(temp - '0');
            }
        }
    }

    // We need to somehow get all possible state transitions

    cout << "::> Found the following state transitions: " << endl;
    for (int i = 0; i < numberOfStates; i++)
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

    queue<set<int>> q;
    map<set<int>, int> mp;

    q.push({0});
    mp[{0}] = 1;

    cout << "-----------------" << endl;
    while (!q.empty())
    {
        set<int> currentSet = q.front();
        q.pop();

        printSet(currentSet);

        set<int> nextSet0, nextSet1;
        for (auto x : currentSet)
        {
            for (auto y : stateTransitions[x][0])
            {
                nextSet0.insert(y);
            }
            for (auto y : stateTransitions[x][1])
            {
                nextSet1.insert(y);
            }
        }

        cout << "            ";
        printSet(nextSet0);
        cout << "            ";
        printSet(nextSet1);
        cout << "\n";

        if (mp.find(nextSet0) == mp.end())
        {
            q.push(nextSet0);
            mp[nextSet0] = 1;
        }
        if (mp.find(nextSet1) == mp.end())
        {
            q.push(nextSet1);
            mp[nextSet1] = 1;
        }
    }

    cout << "Final States: " << endl;
    for (auto x : mp)
    {
        int isFinalState = 0;
        for (auto v : x.first)
        {
            if (finalStates[v])
            {
                isFinalState = 1;
            }
        }

        if (isFinalState)
        {
            printSet(x.first);
            cout << endl;
        }
    }
}