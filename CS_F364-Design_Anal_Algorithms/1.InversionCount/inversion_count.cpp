#include <bits/stdc++.h>
using namespace std;

vector<int> temp;

// We basically have to find out number of inversions that is i < j but a[i] > a[j]
int combineMerge(vector<int> &in, int left, int mid, int right)
{
    // Store current x in temp
    temp.clear();
    for (auto x : in)
    {
        temp.push_back(x);
    }

    int curr = left;
    int leftPtr = left;
    int rightPtr = mid;

    int ans = 0;

    while (leftPtr < mid && rightPtr <= right)
    {
        if (temp[leftPtr] < temp[rightPtr])
        {
            in[curr] = temp[leftPtr];
            leftPtr++;
        }
        else
        {
            in[curr] = temp[rightPtr];
            rightPtr++;
            ans += mid - leftPtr;
        }
        curr++;
    }

    while (leftPtr < mid)
    {
        in[curr] = temp[leftPtr];
        leftPtr++;
        curr++;
    }

    while (rightPtr <= right)
    {
        in[curr] = temp[rightPtr];
        rightPtr++;
        curr++;
    }

    return ans;
}

int mergeSort(vector<int> &in, int left, int right)
{
    int answer = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;

        answer += mergeSort(in, left, mid);
        answer += mergeSort(in, mid + 1, right);
        answer += combineMerge(in, left, mid + 1, right);
    }
    return answer;
}

int main()
{
    freopen("inversion_count.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int m = 0; m < counter; m++)
    {
        cout << "----------- TEST CASE " << m + 1 << " -----------" << endl;

        int n;
        cin >> n;
        vector<int> input(n);
        for (int i = 0; i < n; i++)
            cin >> input[i];

        cout << "Before: ";
        for (auto x : input)
        {
            cout << x << ' ';
        }
        cout << endl;

        int ans = mergeSort(input, 0, input.size() - 1);

        cout << "After: ";
        for (auto x : input)
        {
            cout << x << ' ';
        }
        cout << endl;
        cout << "Answer: " << ans << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}