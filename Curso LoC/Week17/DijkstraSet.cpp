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
    set<pair<int, int>> q;///{dist[v], v}
    for (int i = 1; i <= n; i++)
        q.insert({dist[i], i});
 
    for (int round = 1; round <= n; round++) {
        ///choose the vertex that is not used and has min dist
        /*int v = -1;
        for (int i = 1; i <= n; i++)
            if (!used[i] && (v == -1 || dist[i] < dist[v])) {
                v = i;
            }*/
 
        //pair<int, int> p = *q.begin();
        //int v = p.second;
 
        int v = q.begin()->second;
        q.erase(q.begin());
 
        ///go through neighbours of each vertex only once --- we will use each edge twice in total
        ///update neighbours
        for (auto [u, w] : g[v])
            if (dist[u] > dist[v] + w) {
                q.erase({dist[u], u});
                dist[u] = dist[v] + w;
                q.insert({dist[u], u});
            }
 
    }
 
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    return 0;
}