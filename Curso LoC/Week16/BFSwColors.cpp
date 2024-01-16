#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
const int N = 1e5 + 5;
const int INF = 1000000000;
int n, m;
vector<pair<int, int>> g[N];
int dist[N][4]; ///dist[v][1], dist[v][2], dist[v][3]
pair<int, int> par[N][4];
 
void find_path(int v, int c) {
    if (v == 0)
        return;
    find_path(par[v][c].first, par[v][c].second);
    cout << v << ' ';
}
 
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    ///par[1][...] = 0
    for (int i = 2; i <= n; i++)
        for (int c = 1; c <= 3; c++)
            dist[i][c] = INF;
    queue<pair<int, int>> q; 
    q.push({1, 1}); //{to, color}
    q.push({1, 2});
    q.push({1, 3});
 
    while (!q.empty()) {
        int v = q.front().first;
        int c = q.front().second;
        ///auto [v, c] = q.front();
        q.pop();
 
        ///for (auto p : g[v]) { u = p.first, uc = p.second}
        for (auto i : g[v])
            if (dist[i.first][i.second] == INF && i.second != c) {
                dist[i.first][i.second] = dist[v][c] + 1;
                par[i.first][i.second] = {v, c};
                q.push({i.first, i.second});
            }
    }
    ///min({3, -1, 4})
    int ans = min({dist[n][1], dist[n][2], dist[n][3]});
    if (ans == INF) {
        cout << "NO";
    } else {
        cout << "YES\n";
        cout << ans + 1 << "\n";
        if (dist[n][1] == ans)
            find_path(n, 1);
        else if (dist[n][2] == ans)
            find_path(n, 2);
        else
            find_path(n, 3);
    }
    return 0;
}