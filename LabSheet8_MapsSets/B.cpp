// We iterate through the string and we start replacing numbers from the right side
// since replacing from left side will give you bigger numbers
// so if we have 1223 -> 1221 and since this is a smaller number, we get 1331
// for 23545 -> 23542 -> 23532 -> 23632
// if we have 1234 -> 1231 -> 1221 -> 1331
// Edge Case 
// 1
// 9 -> should give 11

// Split test cases whenever we can
// Odd and Even cases :)
// In odd length, we have middle element which can be anything
// In even, it's mirrored about center

#include <iostream>
using namespace std;

int isPalindrome(string x){
    int result = 1;
    for(int i=0; i<x.size()/2; i++){
        if(x[i] != x[x.size() - 1]){
            result = 0;
        }
    }
    return result;
}

string addOneToMiddle(string x){
    if(x.size()%2 == 0){
        // even length meaning 1331
        // size is 4
        // we need 1 index so
        int mid = x.size() - 1;
        if(x[mid + 1] != '9'){
            
        }
    }
}

int main(){
    freopen("Inputs/B.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int len;
        cin >> len;

        string input;
        cin >> input;

        if(isPalindrome(input)){
            cout << addOneToMiddle(input) << endl;
        }

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}