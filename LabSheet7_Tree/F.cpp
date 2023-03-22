// In this question, we merge in sets of thing I think
// But I'm not sure how we keep track of them :)
// Hmm another solution is 
// So apparently the logic is to use a minheap
// because we take first element of all the arrays put them 

#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    int* arr;
    int heapSize;

    MinHeap(int* input, int maxSize){
        arr = input;
        heapSize = maxSize;
    }

    int getParent(int i){
        return i/2;
    }

    int getLeft(int i){
        return 2*i + 1;
    }

    int getRight(int i){
        return 2*i + 2;
    }

    void buildMinHeap(){
        for(int i=heapSize/2; i>=0; i--){
            minHeapify(i);
        }
    }

    void minHeapify(int i){
        int l = getLeft(i);
        int r = getRight(i);
        int smallest;

        // comparing l and r and finding the smaller
        if(l <= heapSize && arr[l] < arr[i]){
            smallest = l;
        }
        else smallest = i;

        // then compare smallest with i
        if(r <= heapSize && arr[r] < arr[smallest]){
            smallest = r;
        }

        if(smallest != i){
            swap(arr[smallest], arr[i]);
            minHeapify(smallest);
        }
    }

    void sortHeap(){
        int counter = 0;
        int output[heapSize];

        
    }
};

int main(){
    freopen("Inputs/F.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++){
        cout << '----------- TEST CASE ' << i + 1 << ' -----------' << endl;

        vector<vector<int>> input;
        // Make variables for storing no of rows and columns
        int noOfRows, noOfCols;
        // Input no of rows
        cin >> noOfRows;
        // Loop through all rows and add columns into an input
        for(int t=0; i<noOfRows; t++){
            cin >> noOfCols;
            // Take input of each row
            vector<int> in;
            for(int k=0; k<noOfCols; k++){
                int temp;
                cin >> temp;
                in.push_back(temp);
            }
            // Push row to the main vector
            input.push_back(in);
        }




        cout << '--------- END TEST CASE ' << ' ---------' << endl;
    }
}