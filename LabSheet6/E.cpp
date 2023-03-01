// Okay so in this question, we need to find max
// of each sliding window, we can do that in O(n*k)
// but given time complextity is O(n), so we need to figure that out
// Hint given is dequeue - both sided queue
// Hmm, so let's see

// Test case:
// 8 3
// 1 3 -1 -3 5 3 6 7

// Initial approach was to keep track of maximum and see 
// But then when we remobve a max number, there is no way to find
// the previous maximum Can we keep track of maximums in an array

// Can we track maximums and minmums let's see
// -3 -1 1 5
// So we can use a dequeue, We don't have to care for min as long
// As we get max, so we use a dequeue and only keep track of the max
// We pop if the max is on the left side let's say and then carry on

// ahh but, let's say we have 3 1 2 0
// If we use deq -> 0 2 1 3
// We get answer as 3 1 but we should get 3 0
#include <iostream>
#include <deque>

using namespace std;

int main(){
    freopen("E.txt", "r", stdin);

    int inputLength, windowSize;
    cin >> inputLength >> windowSize;

    int input[inputLength];
    for(int i=0; i<inputLength; i++){
        cin >> input[i];
    }

    deque<int> deq;
    // First take care of initial window
    for(int i=0; i<windowSize; i++){
        if(deq.empty()){
            deq.push_back(input[i]);
        }else{
            if(deq.front() < input[i]){
                deq.push_front(input[i]);
            }else{
                deq.push_back(input[i])
            }
        }
    }
    for(int i=0; i<inputLength - windowSize + 1; i++){
        cout << input[i] << " ";
    }

    
}