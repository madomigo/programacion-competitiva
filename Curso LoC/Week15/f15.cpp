#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, d;
    cin >> n >> m >> d;
    set<pair<int,int>> s;
    vector<int> ans (n);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert({x,i});
    }
    int days = 0;
    while (s.size()) {
        days++;
        auto it = s.begin();
        while(it!=s.end()){
            int time = it -> first;
            int pos = it -> second;
            ans[pos] = days;
            auto p = it;
            it = s.lower_bound({time+1+d, 0});
            s.erase(p);
        }
    }
    cout << days << '\n';
    for (auto i : ans) 
        cout << i << ' ';
    cout << '\n';
}