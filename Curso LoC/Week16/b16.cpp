#include <bits/stdc++.h>
using namespace std;

int sx, sy, fx, fy, dist[10][10];
pair<int, int> p[10][10];
const int dx[8] = {-2, -1, 2, -1, 1, -2, 1, 2};
const int dy[8] = {-1, -2, -1, 2, -2, 1, 2, 1};

void ans (int x, int y) {
    if (x == 0 && y == 0) return;
    ans(p[x][y].first, p[x][y].second);
    cout << char('a' + x - 1) << y << "\n";
}

int main () {
    char x, y;
    cin >> x >> y;
    sx = x - 'a' + 1;
    sy = y - '0';

    cin >> x >> y;
    fx = x - 'a' + 1;
    fy = y - '0';

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            dist[i][j] = -1;
        }
    } 

    queue<pair<int,int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax >= 1 && ax <= 8 && ay >= 1 && ay <= 8 && dist[ax][ay] == -1) {
                dist[ax][ay] = dist[x][y] + 1;
                q.push({ax, ay});
                p[ax][ay] = {x, y};
            }
        }
    }
    ans(fx, fy);
}