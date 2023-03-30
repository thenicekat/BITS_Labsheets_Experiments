// We iterate through the string and we start replacing numbers from the right side
// since replacing from left side will give you bigger numbers
// so if we have 1223 -> 1221 and since this is a smaller number, we get 1331
// for 23545 -> 23542 -> 23532 -> 23632
// if we have 1234 -> 1231 -> 1221 -> 1331