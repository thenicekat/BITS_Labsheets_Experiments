#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/C.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take input
        int inLenA, inLenB;
        cin >> inLenA;
        int input_a[inLenA];
        for (int i = 0; i < inLenA; i++)
        {
            cin >> input_a[i];
        }
        cin >> inLenB;
        int input_b[inLenB];
        for (int i = 0; i < inLenB; i++)
        {
            cin >> input_b[i];
        }

        int found = 0;

        int low = 0;
        int high = inLenA;

        while (low <= high && !found)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = (inLenA + inLenB + 1)/2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : input_a[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : input_b[cut2 - 1];
            int right1 = (cut1 == inLenA) ? INT_MAX : input_a[cut1];
            int right2 = (cut2 == inLenB) ? INT_MAX : input_b[cut2];

            if (left1 <= right2 && left2 <= right1)
            {
                if ((inLenA + inLenB) % 2 == 0)
                {
                    cout << (max(left1, left2) + min(right1, right2)) / 2.0 << fixed << setprecision(5) << endl;
                    found = 1;
                }
                else
                {
                    cout << max(left1, left2) << fixed << setprecision(5) << endl;
                    found = 1;
                }
            }
            else if (left1 > right2)
            {
                high = cut1 - 1;
            }
            else
            {
                low = cut1 + 1;
            }
        }

        if (!found)
            cout << 0 << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}