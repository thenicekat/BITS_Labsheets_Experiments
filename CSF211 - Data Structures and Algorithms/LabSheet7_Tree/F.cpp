// In this question, we merge in sets of thing I think
// But I"m not sure how we keep track of them :)
// Hmm another solution is
// So apparently the logic is to use a minheap
// because we take first element of all the arrays put them

// So there are 2 logics for this question, one being merging two vectors separately
// then pushing them to the vector and removing the initially added ones 
// but another logic is that we use heap of size k and this gives us time
// complexity of (k + 2(n-k))logk = nlogk

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    freopen("Inputs/F.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        vector<vector<int>> input;
        // Make variables for storing no of rows and columns
        int noOfArrays, noOfElementsInArray;
        // Input no of rows
        cin >> noOfArrays;
        // Loop through all rows and add columns into an input
        for (int t = 0; t < noOfArrays; t++)
        {
            cin >> noOfElementsInArray;
            // Take input of each row
            vector<int> in;
            for (int k = 0; k < noOfElementsInArray; k++)
            {
                int temp;
                cin >> temp;
                in.push_back(temp);
            }
            // Push row to the main vector
            input.push_back(in);
        }

        // We have to only put counter number of elements so that we get
        // timecomplexity of nlog(counter)
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;
        // Pair syntax will be (number, (array_index, number_index))

        // We take pair, because we need to keep track of the element and the array number
        for (int i = 0; i < noOfArrays; i++)
        {
            // Pushing the first element and the array number
            pq.push(make_pair(input[i][0], make_pair(i, 0)));
        }

        vector<int> result;
        while(!pq.empty()){
            // Retrieve the top most pair
            pair<int, pair<int, int>> x = pq.top();
            // Push the element into an array
            result.push_back(x.first);
            // Pop the element from the array
            pq.pop();

            // Now we need to add the next element from the same array
            // We check if the the next element in the same array is less than the array size
            int arrayIndex = x.second.first;
            int numberIndex = x.second.second;
            if(numberIndex + 1 < input[arrayIndex].size()){
                pq.push(
                    make_pair(input[arrayIndex][numberIndex + 1], make_pair(arrayIndex, numberIndex + 1))
                );
            }
        }

        for(auto x: result){
            cout << x << " ";
        }
        cout << endl;

        cout << "--------- END TEST CASE " << " ---------" << endl;
    }
}