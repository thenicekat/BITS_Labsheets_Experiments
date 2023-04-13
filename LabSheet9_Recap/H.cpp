// Hint: Binary Search :)
// hm so we can binary search on (min, max) each time
// then if we get sum greater than mid,
// we code
#include <bits/stdc++.h>
using namespace std;

int checkIfPossible(int books[], int booksLength, int noOfPeople, int barrier){
    int noOfStudents = 1;
    int currStudent = 0;
    
    int i = 0; 
    while(i < booksLength){
        while(currStudent <= barrier){
            currStudent += books[i];
            i++;
        }
        
        // Add to students list
        noOfStudents++;

        currStudent = 0;        
    }
    return noOfStudents == noOfPeople;
}

int main(){
    freopen("Inputs/H.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int noOfBooks, noOfPeople;
        int books[noOfBooks];

        cin >> noOfBooks >> noOfPeople;

        int sumOfBooks, maxBook = 0, minBook = INT_MAX;

        // In n we loop and get input
        for(int i=0; i<noOfBooks; i++){
            cin >> books[i];
            sumOfBooks += books[i];
            maxBook = max(maxBook, books[i]);
            minBook = min(minBook, books[i]);
        }

        if(noOfBooks < noOfPeople){
            cout << -1 << endl;
        }else if(noOfBooks == noOfPeople){
            cout << maxBook << endl;
        }else{
            int start = minBook;
            int end = sumOfBooks;
            int res = -1;

            while(start <= end){
                int mid = (start + end) >> 1;
                
                if(checkIfPossible(books, noOfBooks, noOfPeople, mid)){
                    end = mid - 1;
                    res = mid;
                }else{
                    start = mid + 1;
                }
            }
            cout << res << endl;
        }

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}