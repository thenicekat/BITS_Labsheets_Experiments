// We go case by case
// 6 4
// 4 1 2 1 1 2 = 11
// 3 6 3 3 = 15
// for them to be equal
// 1. Their sum should be even else directly we can say no 
// 2. Difference will always be even because they should be both even or both odd
// 3. Here 4 is there, so the numbers should have a difference of 2
// then loop through the smaller one and check if n+2 in the other map
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Inputs/I.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take input
        // Add these into an array
        // Also add them into a map
        int a, b;
        cin >> a >> b;

        int input_a[a];
        int input_b[b];

        map<int, int> map_a, map_b;

        int sum_a = 0, sum_b = 0;

        for(int i=0; i<a; i++){
            cin >> input_a[i];
            map_a[input_a[i]]++;
            sum_a += input_a[i];
        }
        for(int i=0; i<b; i++){
            cin >> input_b[i];
            map_b[input_b[i]]++;
            sum_b += input_b[i];
        }


        // We check if sum is even
        // if not then it's a direct NO
        if((sum_a + sum_b) % 2 == 0){
            // But is sum is even there's a chance

            // We find the difference
            int difference = abs((sum_a - sum_b)/2);

            if(map_a.size() < map_b.size()){
                for(auto elem: map_a){
                    // For every element in a
                    // we find if there's any element smaller than difference or bigger than difference
                    if(map_b.find(elem.first + difference) != map_b.end()){
                        cout << "Yes" << endl;
                        break;
                    }
                    if(map_b.find(elem.first - difference) != map_b.end()){
                        cout << "Yes" << endl;
                        break;
                    }
                }
            }else{
                for(auto elem: map_b){
                    // For every element in a
                    // we find if there's any element smaller than difference or bigger than difference
                    if(map_a.find(elem.first + difference) != map_a.end()){
                        cout << "Yes" << endl;
                        break;
                    }
                    if(map_a.find(elem.first - difference) != map_a.end()){
                        cout << "Yes" << endl;
                        break;
                    }
                }
            }
        }else{
            cout << "No" << endl;
        }

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}