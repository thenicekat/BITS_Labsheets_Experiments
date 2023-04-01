// The asked time complexity if O(qlogq) 
// for every 1 query, we make a map and add it to the map which makes it logq
// and for every 2/3 query it becomes logq again if we use upper_bound or lower_bound functions
// so approx -> qlogq 

#include <iostream>
#include <map>
using namespace std;

int main(){
    freopen("Inputs/D.txt", "r", stdin);
    int max;
    cin >> max;

    int queries;
    cin >> queries;

    map<int, int> dict;

    for(int i=0; i<queries; i++){
        int type, k;
        cin >> type >> k;
        
        cout << "----------------------" << endl;
        for(auto m: dict){
            cout << "::>" << m.first << " " << m.second << endl;
        }
        cout << "----------------------" << endl;
        cout << type << " " << k << endl;
        if(type == 1){
            if(dict.find(k) == dict.end()){
                dict[k] = 1;
            }else{
                if(dict[k] == 1) dict.erase(k);
            }
        }
        else if(type == 2){
            if(dict.upper_bound(k) == dict.end()){
                cout << -1 << endl;
            }else{
                cout << dict.upper_bound(k)->first << endl;
            }
        }
        else if(type == 3){
            auto x = dict.lower_bound(k);
            x--;
            if((x) == dict.end()){
                cout << -1 << endl;
            }else{
                cout << (x)->first << endl;
            }
        }
    }
}