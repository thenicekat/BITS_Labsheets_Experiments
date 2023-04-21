// Maybe use a map to keep track of initial indices
// then add difference of these to the answer variable
// For example if we have 2 4 1 3 5 (2:0, 4:1, 1:2, 3:3, 5:4)
// hm we need to find all pairs such that left is higher
// (2,1) (4,1) (4,3)
// ok google says use merge sort
// I do that

// In the merging step, the algorithm uses two pointers to traverse both halves of the sequence. 
// When the element pointed by the right pointer is smaller than the element pointed by the left pointer,
// then all the elements between the left and right pointers in the left half are greater than the 
// element pointed by the right pointer. Thus, we count the number of such elements, add it to 
// the count of out-of-order pairs, and move the right pointer to the next element.

#include <bits/stdc++.h>
using namespace std;

void mergeTogether(int a[], int start, int mid, int end, int *answer){
    int length1 = mid - start + 1;
    int length2 = end - mid;

    int half_a[length1];
    int half_b[length2];

    for(int i=0; i<length1; i++){
        // Goes from a's start to mid + 1
        half_a[i] = a[start + i];
    }
    for(int i=0; i<length2; i++){
        // Goes from mid + 1 to end + 1
        half_b[i] = a[mid + i + 1];
    }

    int left = 0, right = 0, tracker = start;
    
    while(left < length1 && right < length2){
        if(half_a[left] <= half_b[right]){
            a[tracker] = half_a[left];
            left++;
            tracker++;
        }else if(half_a[left] > half_b[right]){
            a[tracker] = half_b[right];
            right++;
            tracker++;
            // cout <<  half_a[left] << " " << half_b[right] << endl;
            (*answer) += (right - left);
        }
    }

    while(left < length1){
        a[tracker] = half_a[left];
        left++;
        tracker++;
    }

    while(right < length2){
        a[tracker] = half_b[right];
        right++;
        tracker++;
    }
}

void mergeRecursive(int a[], int left, int right, int* answer){
    if(left < right){
        int mid = (left + right) / 2;
        mergeRecursive(a, left, mid, answer);
        mergeRecursive(a, mid + 1, right, answer);
        mergeTogether(a, left, mid, right, answer);
    }
}

int main(){
    freopen("Inputs/F.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take input :)
        int inLen;
        cin >> inLen;
        int input[inLen];  
        for(int i=0; i<inLen; i++){
            cin >> input[i];
        }

        int answer = 0;
        mergeRecursive(input, 0, inLen, &answer);

        cout << answer << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}
