#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

    string path;
    cin >> path;

    int n = path.size();
    stack<char> st;
    
    for(int i = 0; i < n; i++){
        if(path[i] == '/'){
            if(!st.empty() && st.top() == '/')
                continue;
            else
                st.push(path[i]);
        }
        else if(path[i] != '.'){
            st.push(path[i]);
        }
        else if(i && path[i] == '.' && path[i - 1] == '.'){
            st.pop();
            while(!st.empty() && st.top() != '/')
                st.pop();
        }           
    }
    
    if(!st.empty() && st.top() == '/')
        st.pop();
    
    if(st.empty())
        st.push('/');
    
    string rev_ans;
    while(!st.empty()){
        rev_ans.push_back(st.top());
        st.pop();
    }

    string ans;
    for(int i = (int)rev_ans.size() - 1; i >= 0; i--)
        ans.push_back(rev_ans[i]);

    cout << ans << endl;


    return 0;
}