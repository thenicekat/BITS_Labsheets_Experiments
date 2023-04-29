#include <stdio.h>
#include <stdlib.h>

/*
Problem I: Bad Search

Here will apply binary search on the answer. 
Let the mid be the middle of left and right in the current iteration, we have to check if the number of comparisions before the start of the mid-th step is greater than half
of the total comparisions or not. To do so we do
    - Find the number of steps left (say rem)
    - Find the number of comparisions done by the last rem steps (rem*(rem - 1) / 2)
    - Find the number of comparisions before the mid-th step by subtracting the above value from the total comparisions.

Say the number of comparisions done before the start of mid-th step be comp_done
    - If comp_done < half of total comparisions, then the answer lies to the right of mid, so we set l to mid + 1
    - If comp_done > half of total comparisions, then the answer lies either at the left of mid or is mid, so we set r = mid
    - If comp_done == half of total comparisions, then we are done and so we stop.
*/

int main(){
 
    long n;
    scanf("%ld", &n);
    
    long midway = (n*(n-1)/2) / 2;
 
    long l = 1, r = n;
 
    while(l<r){
        long mid = (l+r)/2;
        long rem = n - mid;
        long comp_done = n*(n-1)/2 - rem*(rem-1)/2;
        if(comp_done > midway)
            r = mid;
        else if (comp_done == midway) {
            l = mid;
            break;
        }
        else
            l = mid + 1;
    }
 
    printf("%ld\n", l);
 
    return 0;
}

