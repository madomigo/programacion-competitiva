#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int N = 1e5 + 5;

vector<set<pair<int,int>>> g(N);
int dist[N][4];
pair<int, int> par[N][4];

void findANS (int t, int c) {
    if (t == 0)
        return;
    findANS(par[t][c].first, par[t][c].second);
    cout << t << ' ';
}

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) 
        for (int j = 1; j <= 3; j++) 
            dist[i][j] = INF;
         
    int f, t, c;
    for (int i = 0; i < m; i++) {
        cin >> f >> t >> c;
        g[f].insert({t, c});
        g[t].insert({f, c});
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    q.push({1,2});
    q.push({1,3});


    while(!q.empty()) {
        t = q.front().first;
        c = q.front().second;
        q.pop();

        for (auto i : g[t]) {
            if (dist[i.first][i.second] == INF && i.second != c) {
                dist[i.first][i.second] = dist[t][c] + 1;
                par[i.first][i.second] = {t, c};
                q.push({i.first, i.second});
            }
        }
    }
    int ans = min({dist[n][1], dist[n][2], dist[n][3]});
    if (ans == INF) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << ans + 1 << '\n';
    if (dist[n][1] == ans)
        findANS(n, 1);
    else if (dist[n][2] == ans)
        findANS(n, 2);
    else
        findANS(n, 3); 
}