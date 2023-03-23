// We use heapsort to sort the elements in a max heap
// For example:
// 2 5 1 3 -> 1 2 3 5
// 4 5 3 7 -> 3 4 5 7

// Note: here k is given less than n :)

#include <iostream>
#include <vector>
using namespace std;

// Create a heap and code for maxheapify and other class elements
class Heap
{
public:
    vector<int> heapArray;
    int heapSize;

    Heap(vector<int> arr, int c)
    {
        heapArray = arr;
        heapSize = c;
    }

    int getParent(int i)
    {
        return i / 2;
    }

    int getLeft(int i)
    {
        return 2 * i + 1;
    }

    int getRight(int i)
    {
        return 2 * i + 2;
    }

    void maxHeapify(int i)
    {
        int left = getLeft(i);
        int right = getRight(i);
        int largest = i;

        if (left < heapSize && heapArray[left] >= heapArray[i])
        {
            largest = left;
        }
        else
        {
            largest = i;
        }

        if (right < heapSize && heapArray[right] >= heapArray[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heapArray[largest], heapArray[i]);
            maxHeapify(largest);
        }
    }

    void buildMaxHeap()
    {
        for (int i = heapSize / 2; i >= 0; i--)
        {
            maxHeapify(i);
        }
    }

    void heapSort()
    {
        buildMaxHeap();
        for (int i = heapSize - 1; i >= 0; i--)
        {
            swap(heapArray[0], heapArray[i]);
            heapSize--;
            maxHeapify(0);
        }
    }

    void heapInsert(int i){
        
    }
};

int main()
{
    freopen("Inputs/J.txt", "r", stdin);

    int lengthOfArray, k;
    cin >> lengthOfArray >> k;

    // Read inputs
    vector<int> input1(lengthOfArray);
    vector<int> input2(lengthOfArray);
    for (int i = 0; i < lengthOfArray; i++)
    {
        cin >> input1[i];
    }
    for (int i = 0; i < lengthOfArray; i++)
    {
        cin >> input2[i];
    }

    // Make heap 1 and sort it using nlogn
    Heap *h1 = new Heap(input1, lengthOfArray);
    h1->heapSort();
    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << h1->heapArray[i] << " ";
    }
    cout << endl;

    // Make heap 2 and sort it using nlogn
    Heap *h2 = new Heap(input2, lengthOfArray);
    h2->heapSort();
    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << h2->heapArray[i] << " ";
    }
    cout << endl;

    int a = lengthOfArray - 1;
    int b = lengthOfArray - 1;
    for (int i = 0; i < k; i++)
    {
        cout << h1->heapArray[a] + h2->heapArray[b] << endl;
        if(h1->heapArray[a-1] + h2->heapArray[b] > h1->heapArray[a] + h2->heapArray[b-1]){
            a -= 1;
        }else{
            b -= 1;
        }
    }
}
