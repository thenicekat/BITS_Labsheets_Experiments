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
// We get answer as 3 0 but we should get 3 0 F
// If we have example as 3 1 -2 0
// -2 1 3 -> 3 1 hmm still working ahh

// Let's see 3 2 1 0 -> 0 1 2 3 -> 3 0 :)
// Failing test case ;-;

// Had to google, apparently we need to use monotonic dequeue i.e. elements are ordered in decreasing
// order
// https://leetcode.com/problems/sliding-window-maximum/solutions/871317/clear-thinking-process-with-picture-brute-force-to-mono-deque-python-java-javascript/?orderBy=most_votes

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    freopen("E.txt", "r", stdin);

    int inputLength, windowSize;
    cin >> inputLength >> windowSize;

    int input[inputLength];
    for (int i = 0; i < inputLength; i++)
    {
        cin >> input[i];
    }

    deque<int> deq;
    // We make a deque, and then store the values in descending order, and the max will always be the front
    // we pop front if it's remobved from the window
    for (int i = 0; i < inputLength; i++)
    {

        while (!deq.empty() && input[deq.back()] < input[i])
        {
            deq.pop_back();
        }

        deq.push_back(i);

        if(i >= windowSize - 1){
            if(deq.front() == i - windowSize){
                deq.pop_front();
            }
            cout << input[deq.front()] << " ";
        }
    }
}