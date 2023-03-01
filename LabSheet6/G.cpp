// Here basically we need to see how many numbers before it are smaller
// We can keep track of them by keeping a counter and checking if the previous number is greater or not

// 7
// 110 85 65 73 65 78 89

// First, we take 110 and print 1
// next we loop and see if the number is smaller, if yes, we make it zero 
// and do ++ again
// 1 1 1 2 1 2 3

// Hm exactly this won't work, we need to think of something more
// What if we keep track of 