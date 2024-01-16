#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;
const int N = 52;
int v[N][N];
int dist[N][N];
int n, m; 

int op (int a, int b, int c, int d, int cost) {
    if (v[a][b] < v[c][d]) {
        return (3 * (v[c][d] - v[a][b]) + cost);
    }
    else return (v[a][b] - v[c][d] + cost);
}

void dp(int x, int y, int c) {
    if (dist[x][y] <= c) return;
    dist[x][y] = c;

    if (x >= 1) dp(x - 1, y, op(x, y, x - 1, y, c));
    if (x < n - 1) dp(x + 1, y, op(x, y, x + 1, y, c));
    if (y >= 1) dp(x, y - 1, op(x, y, x, y - 1, c));
    if (y < m - 1) dp(x, y + 1, op(x, y, x, y + 1, c));
}

int32_t main () {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            dist[i][j] = INF;
        }
    }

    dp(0, 0, 0);


    cout << dist[n - 1][m - 1] << '\n';
}