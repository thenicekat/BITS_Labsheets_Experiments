// Same as heap I think but gets halved

// I think the logic is we sort the numbers using merge sort which gives us nlogn
// then we do max log per number and this gives us mlogn cause idk
// just assuming
// Like for example, we have 2 13 and 8
// We sort this in nlogn we get 2 8 13

// Apparently we use heap and we get something like
// Then we half the first number we get
// Logic is like we have a max heap and then we keep halving the max until we use up all
// the coupons
// 13 2 8 coupons = 3
// 6 2 8 coupons = 2 -> 8 2 6 coupons = 2
// 4 2 6 coupons = 1 -> 6 2 4 coupons = 1 -> 3 2 4 coupons = 0 :) 

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    freopen("Inputs/G.txt", "r", stdin);

    int lengthOfArray, customers;
    cin >> lengthOfArray >> customers;

    priority_queue<int> input;

    for (int i = 0; i < lengthOfArray; i++)
    {
        int in;
        cin >> in;
        input.push(in);
    }

    int answer = 0;
    while(customers > 0){
            // Find the number
            int x = (input.top() % 2 == 0) ? input.top()/2 : input.top()/2 + 1;
            // Get the number that has to be added to the list
            answer += x;
            int temp = input.top() - x;
            // Pop and push
            input.pop();
            input.push(temp);
            
            customers--;
        }
    cout << answer << endl;
}