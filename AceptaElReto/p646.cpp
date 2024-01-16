#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector<set<pair<int,int>>> g(n + 1);
        int a, b, c;
    
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            g[a].insert({b, c});
            g[b].insert({a, c});
        }
        int k;
        cin >> k;
        while (k--) {
            cin >> a >> b >> c;
            priority_queue<pair<int,int>> q;
            vector<int> visited(n + 1, 0);
            vector<int> dist(n + 1, -1);

            dist[a] = 0;
            q.push({0,a});
            int ans = 0;
            while (!q.empty()) {
                int d = -q.top().first;
                int v = q.top().second;
                q.pop();
                ans = max(ans, dist[v]);
        
                for (auto i : g[v])
                    if (dist[i.first] == -1 && i.second >= c) {
                        dist[i.first] = i.second;
                        q.push({-dist[i.first], i.first});
                    }
                
            }
            if (dist[b] != -1) cout << "SI\n";
            else cout << "NO\n";
        } 
    }
}