// I think in this we can just use stack and strings to ensure that
// We have the correct path
// Pop when we encounter ..
// Ignore .s
// Ignore //

#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    freopen("I.txt", "r", stdin);

    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        printf("--------Test Case No: %lld----------\n", i);

        string input;
        cin >> input;

        string temp = "";

        stack<string> string_stack;

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '/')
            {
                if (temp == ".")
                {
                }
                else if (temp == "..")
                {
                    string_stack.pop();
                }
                else if (temp != "")
                {
                    string_stack.push(temp);
                }
                temp = "";
            }
            else if (i == input.size() - 1)
            {
                temp += input[i];
                if (temp == ".")
                {
                }
                else if (temp == "..")
                {
                    string_stack.pop();
                }
                else if (temp != "")
                {
                    string_stack.push(temp);
                }
                temp = "";
            }
            else
            {
                temp += input[i];
            }
        }

        while (!string_stack.empty())
        {
            cout << string_stack.top() << "/";
            string_stack.pop();
        }

        cout << endl;
    }
}