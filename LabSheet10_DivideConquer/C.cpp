// There's an algorithm for median of 2 sorted arrays
// First we calculate both medians, if equal we return it
// if mLeft > mRight, we ignore right half of left and left part of right
// if mLeft < mRight, we ignore left half of left and right part of right

#include <bits/stdc++.h>
using namespace std;

float recursiveCalculateMedian(int a[], int aleft, int aright, int b[], int bleft, int bright)
{
    float median_a;
    // Check if length of a is even
    if ((aright - aleft) % 2 == 0)
    {
        // if yes then median would be
        median_a = (float)(a[(aright + aleft) / 2 - 1] + a[(aright + aleft) / 2]) / 2;
    }
    else
    {
        median_a = a[(aright + aleft) / 2];
    }

    float median_b;
    // Check if length of b is even
    if ((bright - bleft) % 2 == 0)
    {
        // if yes then medibn would be
        median_b = (float)(b[(bright + bleft) / 2 - 1] + b[(bright + bleft) / 2]) / 2;
    }
    else
    {
        median_b = b[(bright + bleft) / 2];
    }

    if (median_a == median_b)
    {
        return median_a;
    }
    else if (median_a > median_b)
    {
        return recursiveCalculateMedian(a, aleft, (aright + aleft) / 2, b, (bleft + bright) / 2, bright);
    }
    else
    {
        return recursiveCalculateMedian(a, (aright + aleft) / 2, aright, b, bleft, (bleft + bright) / 2);
    }
}

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

        cout << recursiveCalculateMedian(input_a, 0, inLenA, input_b, 0, inLenB) << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}