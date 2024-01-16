#include <bits/stdc++.h>
using namespace std;
vector<set<pair<int,int>>> g;
vector<int> dp;
vector<bool> visited;
vector<int> p;


void dfs(int i) {
    //cout << i << ' ';
    visited[i] = true;
    if (g[i].size() == 0) {
        dp[i] = 0;
        p[i] = -1;
        return;
    }
    for (auto x : g[i]) {
        if(!visited[x.first])
            dfs(x.first);

        if (dp[i] < dp[x.first] + x.second) {
            dp[i] = dp[x.first] + x.second;
            p[i] = x.first;

        }
    }
    return;
}

int main () {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        int a, b, c;
        g.clear();
        g.resize(n + 1);
        p.assign(n + 1, -1);
        dp.assign(n + 1, -1);
        visited.assign(n + 1, 0);
        while (m--) {
            cin >> a >> b >> c;
            g[a].insert({b, c});
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                //cout << i << '\n';
                dfs(i);
                
            }
        }

        int ans = -1;
        int pos;
        for (int i = 1; i <= n; i++) {
            if (dp[i] > ans) {
                ans = dp[i];
                pos = i;
            }
        }
        cout << ans << '\n';

        /*
        for (int i = 1; i <= n; i++) {
            cout << dp[i] << ' ';
        }
        cout << '\n';
        for (int i = 1; i <= n; i++) {
            cout << p[i] << ' ';
        }
        */

        
        cout << pos;
        while (p[pos] != -1) {
            cout << ' ' << p[pos];
            pos = p[pos];
        }
        cout << '\n';
        
        
    }
}