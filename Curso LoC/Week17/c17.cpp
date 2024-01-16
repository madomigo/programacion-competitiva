#include <bits/stdc++.h>
using namespace std;
 
const int N = 1001;
const int INF = 1e9 + 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
 
int n, m;
char a[N][N];
int dist[N][N][4];
 
struct cell {
    int dist, x, y, d;
};
 
struct CellComparator {
    bool operator() (cell a, cell b) {
            return a.dist > b.dist;
    }
};
 
int main() {
    cin >> n >> m;
    int rx, ry, tx, ty;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            if (a[i][j] == 'T') {
                tx = i;
                ty = j;
            }
 
            for (int d = 0; d < 4; d++)
                dist[i][j][d] = INF;
        }
    priority_queue<cell, vector<cell>, CellComparator> q;
    for (int d = 0; d < 4; d++) {
        dist[rx][ry][d] = 0;
        q.push({0, rx, ry, d});
    }
    while (!q.empty()) {
        int distPos, x, y, d;
        distPos = q.top().dist;
        x = q.top().x;
        y = q.top().y;
        d = q.top().d;
        q.pop();
        if (distPos != dist[x][y][d])
            continue;
 
        if (dist[x][y][(d + 1) % 4] > dist[x][y][d] + 1) {
            dist[x][y][(d + 1) % 4] = dist[x][y][d] + 1;
            q.push({dist[x][y][(d + 1) % 4], x, y, (d + 1) % 4});
        }
        if (dist[x][y][(d + 3) % 4] > dist[x][y][d] + 1) {
            dist[x][y][(d + 3) % 4] = dist[x][y][d] + 1;
            q.push({dist[x][y][(d + 3) % 4], x, y, (d + 3) % 4});
        }
 
        int ax = x + dx[d], ay = y + dy[d];
        if (ax >= 0 && ax < n && ay >= 0 && ay < m && (a[ax][ay] == '.' || a[ax][ay] == 'T') && dist[ax][ay][d] > dist[x][y][d] + 2) {
            dist[ax][ay][d] = dist[x][y][d] + 2;
            q.push({dist[ax][ay][d], ax, ay, d});
        }
 
        if (ax >= 0 && ax < n && ay >= 0 && ay < m && a[ax][ay] == '#' && dist[ax][ay][d] > dist[x][y][d] + 11) {
            dist[ax][ay][d] = dist[x][y][d] + 11;
            q.push({dist[ax][ay][d], ax, ay, d});
        }
    }
 
    cout << min({dist[tx][ty][0], dist[tx][ty][1], dist[tx][ty][2], dist[tx][ty][3]});
 
    return 0;
}