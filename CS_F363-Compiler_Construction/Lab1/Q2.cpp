#include <bits/stdc++.h>
using namespace std;

map<int, int> finalStates;
map<int, vector<vector<int>>> stateTransitions;

int checkState(int currentState, string input, int index)
{
    if (index == input.length() && finalStates[currentState])
    {
        return 1;
    }
    if (index == input.length())
    {
        return 0;
    }
    else
    {
        int answer = 0;
        for (int i = 0; i < stateTransitions[currentState][input[index] - '0'].size(); i++)
        {
            // For a particular state, and char, iterate through all states
            answer = answer | checkState(stateTransitions[currentState][input[index] - '0'][i], input, index + 1);
        }
        return answer;
    }
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
        stateTransitions[index] = {{}, {}};

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

    string input;
    cin >> input;
    cout << "::> Found the given input: " << input << endl;

    // We assume start state is 0
    int currentState = 0;
    int ans = checkState(currentState, input, 0);
    // cout << "::> Final State: " << currentState << endl;

    if (ans)
    {
        cout << "Output: Accepted" << endl;
    }
    else
    {
        cout << "Output: Not Accepted" << endl;
    }
}