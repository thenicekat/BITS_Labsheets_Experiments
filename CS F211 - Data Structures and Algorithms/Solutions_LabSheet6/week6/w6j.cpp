#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    string s;
    cin >> s;

    int n = s.size();

    stack<char> st;

    int ans = 0;
    for(int i = 0 ; i < n; i++){
        if(s[i] == ')'){
            if(st.empty())
                ans++;
            else
                st.pop();
        }
        else {
            st.push('(');
        }
    }

    while(!st.empty()){
        ans++;
        st.pop();
    }

    cout << ans << endl;
}