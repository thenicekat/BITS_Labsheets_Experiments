// Hint: Binary Search :)
// hm so we can binary search on (min, max) each time
// then if we get sum greater than mid,
// we code
#include <bits/stdc++.h>
using namespace std;

int checkIfPossible(int books[], int booksLength, int noOfPeople, int barrier)
{
    cout << "Barrier: " << barrier << endl;
    int noOfStudents = 0;
    int currStudent = 0;

    for (int i = 0; i < booksLength; i++)
    {
        if (currStudent + books[i] > barrier)
        {
            noOfStudents++;
            currStudent = books[i];
            if (currStudent > barrier)
                return 0;
        }
        else
        {
            currStudent += books[i];
        }
    }
    if (noOfStudents < noOfPeople)
        return 1;
    return 0;
}

int main()
{
    freopen("Inputs/H.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int k = 0; k < counter; k++)
    {
        cout << "----------- TEST CASE " << k + 1 << " -----------" << endl;

        int noOfBooks = 0, noOfPeople = 0;
        cin >> noOfBooks >> noOfPeople;

        int books[noOfBooks];

        int sumOfBooks = 0;
        int maxBook = 0;
        int minBook = INT_MAX;

        // In n we loop and get input
        for (int m = 0; m < noOfBooks; m++)
        {
            cin >> books[m];
            sumOfBooks += books[m];

            if (books[m] > maxBook)
            {
                maxBook = books[m];
            }

            if (books[m] < minBook)
            {
                minBook = books[m];
            }
        }

        if (noOfBooks < noOfPeople)
        {
            cout << -1 << endl;
        }
        else if (noOfBooks == noOfPeople)
        {
            cout << maxBook << endl;
        }
        else
        {
            int start = minBook;
            int end = sumOfBooks;
            int res = -1;
            while (start <= end)
            {
                int mid = (start + end) >> 1;

                if (checkIfPossible(books, noOfBooks, noOfPeople, mid))
                {
                    end = mid - 1;
                    res = mid;
                }
                else
                {
                    start = mid + 1;
                }
            }
            cout << res << endl;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}