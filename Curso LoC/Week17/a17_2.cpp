#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<pair<int,int>>> g(n + 1);
    priority_queue<pair<int,int>> q;
    vector<int> dist(n + 1, INF);
    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].insert({b, c});
        g[b].insert({a, c});
    }
    dist[1] = 0;
    q.push({0,1}); // {cost, to}
    while (!q.empty()) {
        int d = -q.top().first;
        int v = q.top().second;
        q.pop();
 
        if (d != dist[v])
            continue;
 
        for (auto i : g[v])
            if (dist[i.first] > dist[v] + i.second) {
                dist[i.first] = dist[v] + i.second;
                q.push({-dist[i.first], i.first});
            }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}