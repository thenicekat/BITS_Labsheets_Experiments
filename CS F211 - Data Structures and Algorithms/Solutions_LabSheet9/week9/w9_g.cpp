#include <bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
    return a + b > b + a;
}

int main(){

    int n;
    cin >> n;
    
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    sort(s.begin(), s.end(), compare);
	    
	string ans;
	    
	for(auto x : s) ans.append(x);

    cout << ans << endl;

    return 0;
}