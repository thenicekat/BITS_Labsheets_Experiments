#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool Compare(Job ja, Job jb)
{
    return ja.profit > jb.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    vector<int> ans;
    sort(arr, arr + n, Compare);
    return ans;
}

int main()
{
    int n = 4;
    
}