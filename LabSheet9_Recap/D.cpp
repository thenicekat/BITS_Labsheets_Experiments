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