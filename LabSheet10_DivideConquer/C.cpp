// There's an algorithm for median of 2 sorted arrays
// First we calculate both medians, if equal we return it
// if mLeft > mRight, we ignore right half of left and left part of right
// if mLeft < mRight, we ignore left half of left and right part of right