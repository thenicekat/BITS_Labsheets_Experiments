#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;

    int n = s.size();
    set<string> st;
    set<string> ans;

    for(int i = 0; i <= n - 10; i++){
        string t = s.substr(i, 10);
        if(st.count(t)){
            ans.insert(t);
        }
        else{
            st.insert(t);
        }
    }

    cout << ans.size() << endl;

    for(auto t : ans){
        cout << t << endl;
    }

    return 0;
}