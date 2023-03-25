// Same as heap I think but gets halved

// I think the logic is we sort the numbers using merge sort which gives us nlogn
// then we do max log per number and this gives us mlogn cause idk
// just assuming
// Like for example, we have 2 13 and 8
// We sort this in nlogn we get 2 8 13

// Apparently we use heap and we get something like
// Then we half the first number we get
// Logic is like we have a max heap and then we keep halving the max until we use up all
// the coupons
// 13 2 8 coupons = 3
// 6 2 8 coupons = 2 -> 8 2 6 coupons = 2
// 4 2 6 coupons = 1 -> 6 2 4 coupons = 1 -> 3 2 4 coupons = 0 :) 

#include <iostream>
using namespace std;

class MaxHeap
{
    private:
    int *array;
    int heap_size;
    int customers;

    public:
    MaxHeap(int *arr, int size, int noOfDiscountCoupons)
    {
        array = arr;
        heap_size = size;
        customers = noOfDiscountCoupons;
    }

    int getParentElement(int a)
    {
        int x = (a - 1) / 2;
        return x;
    }

    int getLeftElement(int a)
    {
        return (2 * a) + 1;
    }

    int getRightElement(int a)
    {
        return (2 * a) + 2;
    }

    void max_heapify(int i)
    {
        int l = getLeftElement(i);
        int r = getRightElement(i);
        int largest;

        if (l < heap_size && array[l] >= array[i])
        {
            largest = l;
        }
        else
            largest = i;

        if (r < heap_size && array[r] >= array[largest])
        {
            largest = r;
        }

        if (largest != i)
        {
            swap(array[i], array[largest]);
            max_heapify(largest);
        }
    }

    void build_max_heap()
    {
        for (int t = heap_size / 2; t >= 0; t--)
        {
            max_heapify(t);
        }
    }

    void customers_heap(int* res){
        while(customers > 0){
            int x = (2*(array[0]/2) < array[0]) ? array[0]/2 + 1 : array[0]/2;
            (*res) += x;
            array[0] -= x;
            max_heapify(0);
            customers--;
        }
    }

    void print_heap(){
        for(int i=0; i<heap_size; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int return_sum_heap(){
        int ans = 0;
        for(int i=0; i<heap_size; i++){
            ans += array[i];
        }
        return ans;
    }
};

int main()
{
    freopen("Inputs/G.txt", "r", stdin);

    int lengthOfArray, customers;
    cin >> lengthOfArray >> customers;

    int input[lengthOfArray];
    for (int i = 0; i < lengthOfArray; i++)
    {
        cin >> input[i];
    }

    MaxHeap* mh = new MaxHeap(input, lengthOfArray, customers);
    int answer = 0;
    mh->build_max_heap();
    mh->customers_heap(&answer);
    cout << answer << endl;
}