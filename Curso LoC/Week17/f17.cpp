#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int INF = 1e9 + 1;
 
vector<set<pair<int,int>>> g(N);
vector<int> dist(N, INF);
vector<int> dist2(N, INF);
 
int main () {
    int n, m;
    cin >> n >> m;
    int f, t, w;
    for (int i = 0; i < m; i++) {
        cin >> f >> t >> w;
        g[f].insert({t, w});
    }
    dist[1] = 0;
    priority_queue<pair<int,int>> q;
    q.push({-0, 1});
    while (!q.empty()) {
        int d = -q.top().first;
        int v = q.top().second;
        q.pop();
 
        if (d > dist2[v]) continue;
        
        for (auto i : g[v]) {
            int node = i.first;
            int weight = i.second;
            int dis = weight + d;
            if (dis < dist[node]) {
                swap(dis, dist[node]);
                q.push({-dist[node], node});
            }
            if (dis != dist[node] && dist2[node] > dis) {
                dist2[node] = dis;
                q.push({-dist2[node], node});
            }
        }
    }
    if (dist2[n] != INF) cout << dist2[n] << '\n';
    else cout << "-1\n";
}