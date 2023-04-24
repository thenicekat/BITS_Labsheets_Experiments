// Maybe use a map to keep track of initial indices
// then add difference of these to the answer variable
// For example if we have 2 4 1 3 5 (2:0, 4:1, 1:2, 3:3, 5:4)
// hm we need to find all pairs such that left is higher
// (2,1) (4,1) (4,3)
// ok google says use merge sort
// I do that

// In the merging step, the algorithm uses two pointers to traverse both halves of the sequence.
// When the element pointed by the right pointer is smaller than the element pointed by the left pointer,
// then all the elements between the left and right pointers in the left half are greater than the
// element pointed by the right pointer. Thus, we count the number of such elements, add it to
// the count of out-of-order pairs, and move the right pointer to the next element.

#include <bits/stdc++.h>
using namespace std;

void mergeTogether(int a[], int start, int mid, int end, int *answer)
{
    int temp[end - start + 1];

    int i = start, j = mid, k = 0;

    while (i < mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else if (a[i] > a[j])
        {
            temp[k] = a[j];
            j++;
            k++;
            (*answer) += (mid - i);
        }
    }

    while (i < mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (int i = start, k = 0; i <= end; i++, k++)
    {
        a[i] = temp[k];
    }
}

void mergeRecursive(int a[], int left, int right, int *answer)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeRecursive(a, left, mid, answer);
        mergeRecursive(a, mid + 1, right, answer);
        mergeTogether(a, left, mid + 1, right, answer);
    }
}

int main()
{
    freopen("Inputs/F.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take input :)
        int inLen;
        cin >> inLen;
        int input[inLen];
        for (int i = 0; i < inLen; i++)
        {
            cin >> input[i];
        }

        int answer = 0;
        mergeRecursive(input, 0, inLen - 1, &answer);

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}
