// One procedure for map with subarray problems
// Say we have an array 1 2 3 4 5 6 7 8 9
// split into two parts, A and B whose result will be the prefix XOR
// so A ^ B is prefix C
// From here, we get A = C ^ B
// but here xor needed is 0 so, B = 0 => we need A = C i.e. if there exists any previous subarray for which
// cumxor is same, then we get answer okbi
// we have 3 4 7 6 5 4
// cum-xor 3 7 0 6 3 7
// (0, 2) (1, 4) (3, 6)

// Simpler explanation, if we need subarray with given sum ->
// array at any index can be split into currsum and sum
// since we get ________ currsum-sum __________ sum => total = currsum
// now we know currsum from the prefix sum array, and sum is given as input
// so we keep storing indices of currsum with index
// and check if currsum - sum is in the map
#include <iostream>
#include <map>

#define xorNeeded 0

using namespace std;

int main()
{
    freopen("Inputs/F.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take input
        int len;
        cin >> len;
        int input[len];
        for (int i = 0; i < len; i++)
        {
            cin >> input[i];
        }

        int prefixXOR = 0;
        map<int, int> store;

        int answer = 0;

        for (int i = 0; i < len; i++)
        {
            // first find the prefix xor
            prefixXOR ^= input[i];

            // Check if the prefixXor is the xor neededitself
            if(prefixXOR == xorNeeded){
                answer += 1;
            }

            // Otherwise check if there's any previous subarray which had this xor
            //In this case xorNeededeeded is 0
            int prevXORneeded = prefixXOR ^ xorNeeded;

            if(store.find(prevXORneeded) != store.end()){
                // That means it did exist before
                answer += store[prevXORneeded];
            }

            store[prefixXOR]++;
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}