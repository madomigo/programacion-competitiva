#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int INF = 1e9 + 1;

struct road {
    int u, t, w;
};
 
int n, m;
vector<set<pair<int, pair<int,int>>>> g(N);
vector<int> dist (N);

 
int dijkstra(int x) {
    dist[1] = 0;
    for (int i = 2; i <= n; i++)
        dist[i] = INF;
    priority_queue<pair<int,int>> q; //{dist[v], v}
    q.push({0, 1});
    
    while (!q.empty()) {
        int d = -q.top().first;
        int v = q.top().second;
        q.pop();
 
        if (d != dist[v])
            continue;
 
        for (auto i : g[v])
            if (dist[i.first] > dist[v] + i.second.first && i.second.second >= x) {
                dist[i.first] = dist[v] + i.second.first;
                q.push({-dist[i.first], i.first});
            }
    }
    return dist[n];
}
 
int32_t main() {
    cin >> n >> m;
    int x, y, t, w;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> t >> w;
        g[x].insert({y, {t, w}}); // {to, {time, weight}}
        g[y].insert({x, {t, w}});
    }
 
    int l = 0, r = INF;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (dijkstra(m) <= 525600)
            l = m;
        else
            r = m;
    }
    cout << l;
}