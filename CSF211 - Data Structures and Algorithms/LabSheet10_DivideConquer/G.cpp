#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/G.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inputLength, windowSize;
        cin >> inputLength >> windowSize;

        int input[inputLength];
        for (int i = 0; i < inputLength; i++)
        {
            cin >> input[i];
        }

        deque<int> deq;
        // We make a deque, and then store the values in descending order, and the max will always be the front
        // we pop front if it's remobved from the window
        for (int i = 0; i < inputLength; i++)
        {

            while (!deq.empty() && input[deq.back()] < input[i])
            {
                deq.pop_back();
            }

            deq.push_back(i);

            if (i >= windowSize - 1)
            {
                if (deq.front() == i - windowSize)
                {
                    deq.pop_front();
                }
                cout << input[deq.front()] << " ";
            }
        }
        cout << endl;
        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}