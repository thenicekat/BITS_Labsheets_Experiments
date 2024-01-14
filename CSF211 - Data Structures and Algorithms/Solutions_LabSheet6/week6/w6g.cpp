#include <iostream>
#include <stack>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans[n];
    stack<int> st;

    for(int i = 0; i < n; i++){
        ans[i] = 1;
        while(!st.empty() && a[st.top()] <= a[i]){
            int j = st.top();
            st.pop();
            ans[i] += ans[j];
        }
        st.push(i);
    } 

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    
    cout << endl;
}