#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input1.txt", "r", stdin);

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

    map<int, int> finalStates;
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
    map<int, vector<int>> stateTransitions;
    for (int i = 0; i < numberOfStates; i++)
    {
        getline(cin, line);
        ss.str(line);
        ss.clear();

        int index, a, b;
        ss >> index >> a >> b;
        stateTransitions[index] = {a, b};
    }

    cout << "::> Found the following state transitions: " << endl;
    for(int i = 0; i < numberOfStates; i++){
        cout << "::> "<<  i << " " << stateTransitions[i][0] << " " << stateTransitions[i][1] << endl;
    }

    string input;
    cin >> input;
    cout << "::> Found the given input: " << input << endl;

    // We assume start state is 0
    int currentState = 0;
    cout << "::> Flow: ";
    for(int i=0; i<input.length(); i++){
        cout << "->" << currentState;
        int currentChar = input[i] - '0';
        currentState = stateTransitions[currentState][currentChar];
    }
    cout << "->" << currentState;
    cout << endl;

    if(finalStates[currentState]){
        cout << "Output: Accepted" << endl;
    }else{
        cout << "Output: Not Accepted" << endl;
    }
}