// Initially I thought of using stacks but then
// I googled and realized it is using queue
// And using queue you can implement it easily only
// Like we keep printing queue.front until the same number comes, if same number comes,
// we remove the number
// We also need to keep track of these numbers using a frequency array so that they don't become crowded
// on the tail side

// Or it's like we have a queue, and a frequency array, as soon as the frequency crosses 1, we pop 
// that element
// something of this sort can be done