// Again direct map question where we store number of matches a person lost in the map

#include <bits/stdc++.h>
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

        set<int> loserSet;
        set<int> next;

        vector<int> winners, losers;

        // O(n)
        for (int i = 0; i < nMatches; i++)
        {
            int w, l;
            cin >> w >> l;
            
            winners.push_back(w);
            losers.push_back(l);
        }

        for (int i = 0; i < winners.size(); i++)
        {
            next.insert(winners[i]);
        }

        for(int i=0; i<losers.size(); i++){
             if(loserSet.find(losers[i]) != loserSet.end()){
                // It's already there in loserSet
                // then remove from next because they already lost once
                if(next.find((losers[i])) != next.end()){
                    next.erase(next.find((losers[i])));
                }; 
            }else{
                // otherwise add into loserSet and next
                loserSet.insert(losers[i]);
                next.insert(losers[i]);
            }
        }
        
        for(auto i=next.begin(); i!=next.end(); ++i){
            cout << *i << " ";
        }
        cout << endl;

        cout << "--------- END TEST CASE "
             << " ---------" << endl;
    }
}