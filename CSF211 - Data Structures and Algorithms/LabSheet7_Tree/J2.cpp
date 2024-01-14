// Apparently we can use priority queue

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    freopen("Inputs/J.txt", "r", stdin);

    int lengthOfArray, k;
    cin >> lengthOfArray >> k;

    // Read inputs
    priority_queue<int> input1;
    priority_queue<int> input2;
    int input1Arr[lengthOfArray];
    int input2Arr[lengthOfArray];
    for (int i = 0; i < lengthOfArray; i++)
    {
        int x;
        cin >> x;
        input1.push(x);
    }
    for (int i = 0; i < lengthOfArray; i++)
    {
        int x;
        cin >> x;
        input2.push(x);
    }

    for (int i = 0; i < lengthOfArray; i++)
    {
        input1Arr[i] = input1.top();
        input1.pop();
        input2Arr[i] = input2.top();
        input2.pop();
    }

    for(auto x: input1Arr){
        cout << x<< " ";
    }
    cout << endl;
    for(auto x: input2Arr){
        cout << x<< " ";
    }
    cout << endl;

    int visited[lengthOfArray][lengthOfArray] = { 0 };

    priority_queue<pair<int, pair<int, int>>> sumPriorityQueue;
    sumPriorityQueue.push(make_pair(input1Arr[0] + input2Arr[0], make_pair(0, 0)));

    for (int i = 0; i < k; i++)
    {
        pair<int, pair<int, int>> pp = sumPriorityQueue.top();

        if(visited[pp.second.first][pp.second.second] == 1){
            sumPriorityQueue.pop();
            i--;
            continue;
        }

        visited[pp.second.first][pp.second.second] = 1;
        sumPriorityQueue.pop();
        // cout << pp.second.first << "+" << pp.second.second << " " << pp.first << endl;
        cout << pp.first << " ";
        
        sumPriorityQueue.push(make_pair(input1Arr[pp.second.first] + input2Arr[pp.second.second + 1], make_pair(pp.second.first, pp.second.second + 1)));
        sumPriorityQueue.push(make_pair(input1Arr[pp.second.first + 1] + input2Arr[pp.second.second], make_pair(pp.second.first + 1, pp.second.second)));
    }
}