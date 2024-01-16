#include <bits/stdc++.h>
using namespace std;

int main () {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    map<pair<int,int>,int> dist;
    dist[{h1,m1}] = 0;
    queue<pair<int,int>> q;
    q.push({h1,m1});
    int x, y;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        int h = (x + a1) % 24;
        int m = (y + b1) % 60;

        if (dist.find({h,m}) == dist.end()) {
            dist[{h, m}] = dist[{x, y}] + 1;
            q.push({h,m});
        }

        h = (x + a2) % 24;
        m = (y + b2) % 60;

        if (dist.find({h,m}) == dist.end()) {
            dist[{h, m}] = dist[{x, y}] + 1;
            q.push({h,m});
        }
    }
    if (dist.find({h2,m2}) == dist.end())
        cout << -1 << '\n';
    else 
        cout << dist[{h2, m2}] << '\n';
}