#include <bits/stdc++.h> 
using namespace std;
 
const int N = 1002;
const int INF = 1e9 + 1;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
 
int n, m, dist[N][N];
char a[N][N];
 
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dist[i][j] = INF;
        }
    queue<pair<int, int>> q;
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        dist[x][y] = 0;
        q.push({x, y});
    }
 
    while (!q.empty()) {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for (int d = 0; d < 8; d++) {
            int ax = x + dx[d];
            int ay = y + dy[d];
            if (ax >= 1 && ax <= n && ay >= 1 && ay <= m && a[ax][ay] == '.' && dist[ax][ay] == INF) {
                dist[ax][ay] = dist[x][y] + 1;
                q.push({ax, ay});
            }
        }
    }
 
    int mx = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (dist[i][j] != INF)
                mx = max(mx, dist[i][j]);
 
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (dist[i][j] == mx)
                ans.push_back({i, j});
    cout << ans.size() << "\n";
    for (auto el : ans)
        cout << el.first << ' ' << el.second << "\n";
}