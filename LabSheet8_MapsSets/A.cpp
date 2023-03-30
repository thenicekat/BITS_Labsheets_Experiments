// we can use sets and then compare
// comparing sets takes O(size of set)
// hm so we can apparently use the strings initially to give each of them a string like number,
// and then we can compare two of them and check the answer
// we have eat/tea and ate -> all of them will end up being the same string
// but the thing is time complexity
// O(mn [for looping through all letters] + nlogn [for adding them into map] + 26n [for building the hash])