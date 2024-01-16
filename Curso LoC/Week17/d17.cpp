#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int INF = 1e9 + 1;

vector<set<pair<int,pair<int,int>>>> g(N + 1);
queue<pair<int,pair<int,int>>> q;
int dist[N][4];
pair<int,int> par[N][4];
vector<int> vert;

void findANS (int t, int c) {
    if (t == 0)
        return;
    findANS(par[t][c].first, par[t][c].second);
    vert.push_back(t);
}

int main () {
    int n, m;
    cin >> n >> m;
    int f, t, c, w;
    for (int i = 0; i < m; i++) {
        cin >> f >> t >> c >> w;
        g[f].insert({t, {c, w}}); // {to, {color, weight}}
        g[t].insert({f, {c, w}});
    }   
    for (int i = 1; i <= 3; i++) {
        dist[1][i] = 0;
        q.push({0, {1, i}}); // {cost, {to, color}}
    }
    for (int i = 2; i <= n; i++)
        for (int c = 1; c <= 3; c++)
            dist[i][c] = INF;
    while (!q.empty()) {
        int d = -q.front().first;
        int v = q.front().second.first;
        c = q.front().second.second;
        q.pop();

        if (d != dist[v][c]) continue;

        for (auto i : g[v]) {
            int to = i.first, color = i.second.first, weight = i.second.second;

            if (dist[to][color] > dist[v][c] + weight && color != c) {
                dist[to][color] = dist[v][c] + weight;
                par[to][color] = {v, c};
                q.push({-dist[to][color], {to, color}});
            }
        }

    }
    int ans = min({dist[n][1], dist[n][2], dist[n][3]});
    if (ans == INF) {
        cout << "NO";
    } else {
        cout << "YES\n";
        if (dist[n][1] == ans)
            findANS(n, 1);
        else if (dist[n][2] == ans)
            findANS(n, 2);
        else
            findANS(n, 3);

        cout << vert.size() << '\n';
        for (int i : vert) cout << i << ' ';
    }
}