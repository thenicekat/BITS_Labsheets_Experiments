// You have to observe that when you want to change last, 
// then you have to flip twice and you can get there
// so like first example, is 3 2 1 4 -> We go from right and we check if position is wrong
// 1 2 3 4
// In second case, we have 3 4 2 1
// We need to get the 4 in the end
// we do swap of 2
// 4 3 2 1
// then we do 1 2 3 4

// if we have 4 3 5 6 2 1
// we need 6 in the end so, we do 6 5 3 4 2 1
// then we send it to end -> 1 2 4 3 5 6
// then we again go through this and find that 3 is out of place
// so we do 4 2 1 3 5 6
// then we have 3 1 2 4 5 6
// then we have 2 1 3 4 5 6
// 1 2 3 4 5 6
// so answer will be
// 4 6 3 4 

// Can we always replace 2 elements in 4 operations without editing it
// 3 2 1 4 (Input)
// 1 2 3 4 (3)
// 