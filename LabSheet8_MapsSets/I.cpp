// Again direct map question where we store number of matches a person lost in the map

#include <iostream>
using namespace std;

int main()
{
    freopen("Inputs/I.txt", "r", stdin);
    int counter;
    cin >> counter;

    for (int i = 0; i < counter; i++)
    {
        cout << "----------- TEST CASE " << i + 1 << " -----------" << endl;

        int nMatches, nPlayers;
        cin >> nMatches >> nPlayers;

        int loserScore[nPlayers] = {0};

        // O(n)
        for (int i = 0; i < nMatches; i++)
        {
            int w, l;
            cin >> w >> l;

            loserScore[l - 1]++;
        }
        // O(k)
        for(int i=0; i<nPlayers; i++){
            if(loserScore[i] <= 1){
                cout << i + 1 << " ";
            }
        }
        cout << endl;

        // TC = O(n + k) = O(nlogn)
        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}