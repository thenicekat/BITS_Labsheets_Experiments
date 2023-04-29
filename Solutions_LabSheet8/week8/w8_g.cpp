#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }

    int ans = n * (n - 1) * (n - 2) / 6;

    for(int i = 0; i < n; i++){
        map<pair<int,int>, int> cnt;
        for(int j = i + 1; j < n; j++){
            int dy = points[j].second - points[i].second;
            int dx = points[j].first - points[i].first;

            if(dy < 0){
                dy *= -1;
                dx *= -1;
            }

            int gcd = __gcd(dx, dy);
            dx /= gcd;
            dy /= gcd;

            pair<int, int> slope = {dy, dx};
            cnt[slope]++;
        }

        for(auto e : cnt){
            ans -= e.second * (e.second - 1) / 2;
        }
    }

    cout << ans << endl;
}