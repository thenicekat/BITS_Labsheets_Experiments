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
//

#include <iostream>
#include <stack>

using namespace std;

int32_t main()
{
    int counter;
    cin >> counter;

    int input[counter];
    for (int i = 0; i < counter; i++)
    { 
        cin >> input[i];
    }

    stack<int> stack_sec;
    for(int i=0; i<counter; i++){
        int t = 0;
        while(!stack_sec.empty() && stack_sec.top() < input[i]){
            stack_sec.pop();
            t++;
        }

        if(stack_sec.empty()){
            cout << 1 << " ";
        }else{
            
        }
    }
}