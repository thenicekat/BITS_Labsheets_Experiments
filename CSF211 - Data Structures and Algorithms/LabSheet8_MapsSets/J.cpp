// Hm let's say input is 1 0 0 1 1
// We have 2 as the limit
// so we have a variable sliding window thing
// where we go from  (1 0 0 1) 1 -> 4C2 = 6 + 4 = 10 -> 0,0 0,1 0,2 0,3 1,1 1,2 1,3 2,2 2,3 3,3
// After this it becomes 1 0 0 (1 1) -> 2C2 + 2 = 3 -> 3,3 4,4 3,4
// hm so if we take 1 (0 0 1 1) -> (1,1) (1,2) (1,3) 1,4 (2,2) (2,3) 2,4 (3,3) 3,4 4,4
// the bracket ones are common, so basically logic still is same but we need to use map to check they don't
// repeat or probably a set in this case
// hm but this won't be nlogn sad
// let's see if we can optimize it


// if input is 1 1 1 1 -> We get 4C2 + 4 = 10

#include <iostream>
using namespace std;

int main()
{
    freopen("Inputs/J.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int length, bulbs;
        cin >> length >> bulbs;

        // Take input array
        int input[length];
        for (int i = 0; i < length; i++)
        {
            cin >> input[i];
        }

        int litBulbs = 0, unLitBulbs = 0;
        int l = 0, r = 0;

        if (input[0] == 1)
            litBulbs++;
        else
            unLitBulbs++;

        int answer = 0;

        // Use sliding window

        while (l <= r && r < length)
        {
            // If we have more bulbs than needed we decrease left limit
            // O(1)
            if (litBulbs > bulbs)
            {
                input[l] == 1 ? litBulbs-- : unLitBulbs--;
                l++;
            }

            // If we have less than or equal bulbs than needed we increase right limit
            if (litBulbs <= bulbs)
            {
                answer += (r - l) + 1;
                r++;
                input[r] == 1 ? litBulbs++ : unLitBulbs++;
            }
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}