// Given subarray and average k and TC nlogn
// Seem to be of the subarray sum question lmao
// I mean average ok
// we have input = 2 1 3
// prefix sum = 2 3 6

// see if we had subarray with sum = 3, we do it like this
// map { 2: 0, 3: 1, 6: 2}
// we loop and see if sum = 3 then subarray [0, i] = [0, 1]
// then we see that when 6 comes, we check for 6 - 3 also, if it exists then we check that wala array
// which is [2, 2]

// Hmm: https://www.geeksforgeeks.org/count-of-subarrays-with-average-k/

// Let there be a subarray [L, R] whose average is equal to K, then
// => K = average[L, R] = sum[0, R] – sum[0, L-1] / (R – L + 1)
// => (R – L + 1) * K = sum[0, R] – sum[0, L – 1]
// => R * k – (L – 1)* K = sum[0, R] – sum[0, L – 1]
// => sum[0, R] – R * k = sum[0, L – 1]  – (L – 1)* K

// If every element is decreased by K, then the average will also decrease by K. Therefore, the average can be reduced to zero, so the problem becomes finding the number of subarrays having average equals zero.
// The average zero is possible only if:
// sum[0, R] – sum[0, L-1] / (R – L + 1) = 0
// => sum[0, R] = sum[0, L-1]

// In simple, average should be 0, sum should be 0

#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Inputs/D.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take input
        int inLen, average;
        cin >> inLen >> average;
        int input[inLen];
        for (int i = 0; i < inLen; i++)
        {
            int x;
            cin >> x;

            input[i] = x - average;
        }  

        int answer = 0;

        int prefixSum = 0;
        map<int, int> prefixFreq;
        for (int i = 0; i < inLen; i++)
        {
            prefixSum += input[i];
            
            if(prefixSum == 0){
                answer++;
            }
            
            answer += prefixFreq[prefixSum];

            prefixFreq[prefixSum]++;
        }

        cout << answer << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}