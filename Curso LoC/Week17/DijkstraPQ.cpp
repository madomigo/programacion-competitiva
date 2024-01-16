#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
 
const int N = 1e5 + 5;
const int INF = 2000000000;
 
int n, m, dist[N];
vector<pair<int, int>> g[N];
 
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    for (int i = 2; i <= n; i++)
        dist[i] = INF;
    priority_queue<pair<int, int>> q;///{dist[v], v}
    for (int i = 1; i <= n; i++)
        q.push({-dist[i], i});
 
    while (!q.empty()) {
        int d = -q.top().first;
        int v = q.top().second;
        q.pop();
 
        if (d != dist[v])///= d > dist[v], so we already used v before
            continue;
 
        for (auto i : g[v])
            if (dist[i.first] > dist[v] + i.second) {
                dist[i.first] = dist[v] + i.second;
                q.push({-dist[i.first], i.first});
                ///different pairs for the same u
            }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    return 0;
}