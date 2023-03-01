// Okay so in this question, we need to find max
// of each sliding window, we can do that in O(n*k)
// but given time complextity is O(n), so we need to figure that out
// Hint given is dequeue - both sided queue
// Hmm, so let's see

// Test case: 8 3
// 1 3 -1 -3 5 3 6 7

// Initial approach was to keep track of maximum and see 
// But then when we remobve a max number, there is no way to find
// the previous maximum Can we keep track of maximums in an array

// Can we track maximums and minmums let's see
// -3 -1 1 5
// So we can use a dequeue, We don't have to care for min as long
// As we get max, so we use a dequeue and only keep track of the max
// We pop if the max is on the left side let's say and then carry on
