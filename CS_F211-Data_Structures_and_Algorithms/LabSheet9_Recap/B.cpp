// We can make an array to keep track of previous plate and next plate I think
// so like say input is
// | | * * | | * * | *
// 0 1 2 3 4 5 6 7 8 9
// and given * is plate and | is candles
// we make an array of previous candle which will be A
// we make an array of next candle also which will be B
// we also make an array of how many plates wala prefix array C
// prevCandles = [0, 1, 1, 1, 4, 5, 5, 5, 8, 8]
// nextCandles = [0, 1, 4, 4, 4, 5, 8, 8, 8, -1]
// noOfPlates = [0, 0, 1, 2, 2, 2, 3, 4, 4, 5]
// Now query is 3, 8 -> we find where the nearest candle in nextCandles to 3 -> 4
// find the previous candle for 8 -> 8
// Now we find theprefixSum[8] - theprefixSum[4] = 4 - 2

// Total TC = O(3n + q) = O(n + q)

#include <iostream>
using namespace std;

int main()
{
    freopen("Inputs/B.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int inLen, queries;
        cin >> inLen >> queries;
        char input[inLen];
        for (int i = 0; i < inLen; i++)
        {
            cin >> input[i];
        }

        int prevCandles[inLen];
        int prevCandleTracker = -1;
        for (int i = 0; i < inLen; i++)
        {
            if (input[i] == '|')
            {
                prevCandleTracker = i;
            }
            prevCandles[i] = prevCandleTracker;
        }

        int nextCandles[inLen];
        int nextCandleTracker = -1;
        for (int i = inLen - 1; i >= 0; i--)
        {
            if (input[i] == '|')
            {
                nextCandleTracker = i;
            }
            nextCandles[i] = nextCandleTracker;
        }

        int plates[inLen];
        int plateTracker = 0;
        for (int i = 0; i < inLen; i++)
        {
            if (input[i] == '*')
            {
                plateTracker++;
            }
            plates[i] = plateTracker;
        }

        cout << "Prev Candle Array: ";
        for(int x: prevCandles){
            cout << x << " ";
        }
        cout << endl;
        cout << "Next Candle Array: ";
        for(int x: nextCandles){
            cout << x << " ";
        }
        cout << endl;
        cout << "Plates Array: ";
        for(int x: plates){
            cout << x << " ";
        }
        cout << endl;

        for(int i=0; i<queries; i++){
            int l, r;
            cin >> l >> r;

            cout << "Query No " << i + 1 << ": ";
            cout << plates[prevCandles[r]] - plates[nextCandles[l]] << endl;
        }

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}