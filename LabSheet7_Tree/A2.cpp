#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> heap;

    freopen("Inputs/A.txt", "r", stdin);

    int lengthOfArray, discountCoupons;
    cin >> lengthOfArray >> discountCoupons;

    for (int i = 0; i < lengthOfArray; i++)
    {
        int x;
        cin >> x;
        heap.push(x);
    }

    while (discountCoupons > 0)
    {
        int x = heap.top();
        heap.pop();
        x /= 2;

        heap.push(x);

        discountCoupons--;
    }

    int sum = 0;
    for(int i=0; i<lengthOfArray; i++){
        int a = heap.top();
        sum += a;
        heap.pop();
    }

    cout << sum << endl;
}