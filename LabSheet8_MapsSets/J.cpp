// Hm let's say input is 1 0 0 1 1
// We have 2 as the limit
// so we have a variable sliding window thing
// where we go from  (1 0 0 1) 1 -> 4C2 = 6 + 4 = 10
// After this it becomes 1 0 0 (1 1) -> 2C2 + 2 = 4

//if input is 1 1 1 1 -> We get 4C2 + 4 = 10

#include <iostream>
using namespace std;

int main(){
    freopen("Inputs/J.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int length, bulbs;
        cin >> length >> bulbs;

        // Take input array 
        int input[length];
        for(int i=0; i<length; i++){
            cin >> input[i];
        }

        int litBulbs = 0, unLitBulbs = 0;
        int l = 0, r = 1;

        if(input[0] == 1) litBulbs++;
        else unLitBulbs++;

        // Use sliding window
        while(l < r && r < length){
            // If we have less bulbs than needed we increase right limit
            if(litBulbs < bulbs){
                input[r] == 1 ? litBulbs++ : unLitBulbs++;
                r++;
            }

            // If we have more bulbs than needed we decrease left limit
            if(litBulbs > bulbs){
                input[l] == 1 ? litBulbs-- : unLitBulbs--;
                l++;
            }

            if(litBulbs == bulbs && input[l] == 1 && input[r] == 1){
                cout << l << " " << r << " " << litBulbs << " " << unLitBulbs << endl;

                input[r] == 1 ? litBulbs++ : unLitBulbs++;
                r++;
            }
        }

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}