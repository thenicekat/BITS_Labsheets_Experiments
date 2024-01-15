// Simple stack implementation and pop for closing brackets
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    freopen("J.txt", "r", stdin);

    int counter;
    cin >> counter;
    while (counter--)
    {
        string input;
        cin >> input;

        cout << input << " - " << input.size() << " - ";

        stack<char> bracs;
        int answer = 0;

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == ')' && !bracs.empty())
                bracs.pop();
            else if(input[i] == ')' && bracs.empty()){
                answer++;
            }
            else if (input[i] == '(')
                bracs.push(input[i]);
        }

        cout << answer + bracs.size() << endl;
    }
}