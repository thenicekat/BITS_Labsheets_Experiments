// New Logic :)
// Case 1: If we have even number of digits, then we can have 1241 or we can have 1211
// If we have 1211, we just replicate LHS in RHS in mirrored manner
// If we have 1241, we increase the left-middle until the right middle and replicate them
// If both are equal then we keep going until we find numbers which are not equal
// Case 2: If we have odd number of digits, then we can have 12345 and 12311
// In the case of 12345, since left-to-middle is smaller than right-to-middle, increase middle and replicate
// In the case of 12311, since left-to-middle is bigger, replicate the LHS in RHS in mirrored manner
// Case 3: If you have 9 anywhere, then still we add 1 to it and continue using a carry

#include <iostream>
using namespace std;

void print(int input[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << input[i];
    }
    cout << endl;
}

int checkAll9(int input[], int length)
{
    int all9 = 1;
    for (int i = 0; i < length; i++)
    {
        if (input[i] != 9)
        {
            all9 = 0;
        }
    }

    if (all9 == 1)
    {
        cout << 1;
        for (int i = 0; i < length - 1; i++)
        {
            cout << 0;
        }
        cout << 1 << endl;
    }

    return all9;
}

void findNextPalindrome(int input[], int length)
{
    int leftMiddle = length / 2 - 1;
    int middle = length / 2;
    int rightMiddle = length / 2 + 1;

    if (length % 2 == 0)
    {
        rightMiddle = middle;
    }

    int leftTracker = leftMiddle;
    int rightTracker = rightMiddle;

    int isLeftSmall = 0;
    while (leftTracker >= 0 && rightTracker < length && input[leftTracker] == input[rightTracker])
    {
        leftTracker--;
        rightTracker++;
    }
    // if leftTracker < 0, that means that it's a palindrome :)
    // otherwise left is smaller
    if (leftTracker < 0 || input[leftTracker] < input[rightTracker])
    {
        isLeftSmall = 1;
    }
    // We replace right with left side
    // O(n)
    while (leftTracker >= 0 && rightTracker < length)
    {
        input[rightTracker] = input[leftTracker];
        leftTracker--;
        rightTracker++;
    }

    // We take a variable to check if left half is smaller when reversed or not
    // if it's smaller we need to increase the middle by 1 and continue
    // otherwise we can just replace right half
    leftTracker = leftMiddle;
    rightTracker = rightMiddle;
    if (isLeftSmall)
    {
        // Here for even we increase left but for odd we increase middle
        int carryTracker = length % 2 == 0 ? leftTracker : middle;
        // We keep going left until it finds the next non 9 number
        while (carryTracker >= 0 && input[carryTracker] == 9)
        {
            input[carryTracker] = 0;
            carryTracker--;
        }
        input[carryTracker]++;
    }
    
    while (leftTracker >= 0 && rightTracker < length)
    {
        input[rightTracker] = input[leftTracker];
        leftTracker--;
        rightTracker++;
    }
}

int main()
{
    freopen("Inputs/B.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int length;
        cin >> length;
        int input[length];
        for (int i = 0; i < length; i++)
        {
            char temp;
            cin >> temp;
            input[i] = temp - '0';
        }

        cout << "Input: ";
        print(input, length);
        // This is edge case for 99 and cases like those
        if (!checkAll9(input, length))
        {
            findNextPalindrome(input, length);
            print(input, length);
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}