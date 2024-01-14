// let's say we have a b c d e f
// sub array differences will be 
// Sigma(subarrays) Max - Min = Sigma(subarrays) Max - Sigma(subarrays) Min
// Now for Sigma(subarrays) Max we use a stack
// so like if we have 4 6 5, to find the number of subarrays with 4 as minimum, we use a stack
// such that we get previous greater element and next greater element
// similarly for maximum, we use previous smaller and next smaller element concept :)

// sum of mins for 4 5 6 = 4 + 4 + 4 + 5 + 5 + 6 = 28

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Inputs/C.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inLen;
        cin >> inLen;
        int input[inLen];
        for(int i=0; i<inLen; i++){
            cin >> input[i];
        }
        

        // Using greater stacks gives max sum
        // we can convert using 4 separate stakcs to using one stack
        // so basically everytime we pop, that basically means that the number is less than the one we are inserting right?
        // so we can say that the number of sub arrays are 
        
        // Subtract all maximums lol
        int answer = 0;
        stack<int> maxStack;
        int maxStackIndices[inLen];
        for(int i=0; i<=inLen; i++){
            // we iterate every element
            while(!maxStack.empty() && (i == inLen || input[maxStack.top()] <= input[i])){
                // we find the most recent 
                int j = maxStack.top();
                maxStack.pop();
                
                int k = maxStack.empty() ? -1 : maxStack.top();
        
                answer +=  (i - j) * (j - k) * input[j];
             }
            maxStack.push(i);
        }  

        // Subtract all minimums lol
        stack<int> minStack;
        int minStackIndices[inLen];
        for(int i=0; i<=inLen; i++){
            // we iterate every element
            while(!minStack.empty() && (i == inLen || input[minStack.top()] >= input[i])){
                // we find the most recent 
                int j = minStack.top();
                minStack.pop();
                
                int k = minStack.empty() ? -1 : minStack.top();
        
                answer -=  (i - j) * (j - k) * input[j];
             }
            minStack.push(i);
        }   

        cout << answer << endl;
        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}