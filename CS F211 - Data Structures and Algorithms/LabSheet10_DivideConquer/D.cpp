// ok fuck you -> me I mean
// https://www.geeksforgeeks.org/pancake-sorting/

#include <bits/stdc++.h>
using namespace std;

// Make a flip function which does the flips which the question describes
// O(n) :)
void flip(int arr[], int x)
{
    int temp;
    int start = 0;
    while (start < x)
    {
        temp = arr[start];
        arr[start] = arr[x];
        arr[x] = temp;
        x--;
        start++;
    }
}

// Make a function that returns max index in the array
int maxIndex(int arr[], int x)
{
    int maxIndex = 0;
    for (int i = 1; i < x; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    freopen("Inputs/D.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        // Taking input
        int inLen;
        cin >> inLen;
        int input[inLen];
        for (int i = 0; i < inLen; i++)
        {
            cin >> input[i];
        }

        vector<int> ans;

        // Loop from end
        for (int i = inLen; i > 1; i--)
        {
            int maxI = maxIndex(input, i);

            if (maxI != i - 1)
            {
                if (maxI != 0)
                {
                    ans.push_back(maxI);
                    // flip such that maxI goes to 0
                    flip(input, maxI);
                }
                ans.push_back(i - 1);
                // flip again such that maxI comes to currIndex
                flip(input, i - 1);
            }
        }

        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}