#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9 + 1;

vector<int> c(N);
vector<set<int>> g(N);
vector<int> dist (N, INF);

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    int f, t;
    for (int i = 0; i < m; i++) {
        cin >> f >> t;
        g[f].insert(t);
        g[t].insert(f);
    }
    dist[1] = c[1];
    priority_queue<pair<int,int>> q;
    q.push({-c[1], 1});
    while (!q.empty()) {
        int d = -q.top().first;
        int v = q.top().second;
        q.pop();

        if (d != dist[v]) continue;

        for (auto i : g[v]) {
            if (dist[i] > dist[v] + c[i]) {
                dist[i] = dist[v] + c[i];
                q.push({-dist[i], i});
           }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}