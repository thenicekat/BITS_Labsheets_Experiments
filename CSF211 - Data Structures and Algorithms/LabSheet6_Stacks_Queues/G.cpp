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

// Stack: 110 counter = 1
// Answer: 1
// Stack 110 85 counter = 1
// Answer: 1
// Stack 110 85 65 counter = 1
// Answer: 1
// Stack 110 85 65 73 -> 110 85 73 counter = 1

// Bruh we just have to find the previous greater number ;-;
// And for that we use stack
// Say we have 110 85 65 73 65 78 89
// Stack has nothing so answer: -1
// Stack has 0:110 and 1:85 and since 85 is smaller, we get answer: -1 0
// Same for 65 we get 0:110 1:85 2:65 and answer: -1 0 1
// For 73 but, we need to pop 65, so stack 0:110 1:85 3:73 and answer -1 0 1 1
// For 65 again, we get 3 directly so answer -1 0 1 1 3
// For 78, we pop until 1 so -1 0 1 1 3 1 0
// for 89, we pop 85 also, so we get, now we just have to subtrack indices
// Answer: 1 1 1 2 1 4 6

#include <iostream>
#include <stack>

using namespace std;

int32_t main()
{
    freopen("G.txt", "r", stdin);

    int counter;
    cin >> counter;

    int input[counter];
    for (int i = 0; i < counter; i++)
    { 
        cin >> input[i];
    }

    stack<int> stack_sec;
    int answer[counter];
    for(int i=0; i<counter; i++){
        while(!stack_sec.empty() && input[stack_sec.top()] < input[i]){
            stack_sec.pop();
        }

        if(stack_sec.empty()){
            answer[i] = -1;
        }else{
            answer[i] = stack_sec.top();
        }

        stack_sec.push(i);
    }

    for(int i=0; i<counter; i++){
        cout << i - answer[i] << " ";
    }
}