// Use two maps?
// you add all from B into map
// 11 4
// 2 1 2 5 7 1 9 3 6 8 8
// 2 1 8 3

// then you iterate through the first one and increase count
// then you print in the order given in B
// maybe we sort them first :) the elements in A

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Inputs/H.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        // Take input
        int a, b;
        cin >> a >> b;

        int array_a[a];
        int array_b[b];
        for(int i=0; i<a; i++){
            cin >> array_a[i];
        }
        for(int i=0; i<b; i++){
            cin >> array_b[i];
        }

        // Sort the array
        sort(array_a, array_a + a);
        
        // Make a map for b and store all keys with values as 0
        // O(b)
        map<int, int> map_b;
        for(int i=0; i<b; i++){
            map_b[array_b[i]] = 0;
        }

        // Iterate through a - O(a)
        for(int i=0; i<a; i++){
            if(map_b.find(array_a[i]) != map_b.end()){
                map_b[array_a[i]]++;
            }
        }

        // Iterate through b and print b elements first
        for(int i =0; i<b; i++){
            for(int j=0; j<map_b[array_b[i]]; j++){
                cout << array_b[i] << " ";
            }
        }

        for(int i=0; i<a; i++){
            if(map_b.find(array_a[i]) == map_b.end()){
                cout << array_a[i] << " ";
            }
        }

        cout << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}