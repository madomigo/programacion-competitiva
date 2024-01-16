#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b;

    cin >> n >> m >> a >> b;

    vector<set<int>> graph (n + 1);
    int fr, to;
    for (int i = 0; i < m; i++) {
        cin >> fr >> to;
        graph[fr].insert(to);
        graph[to].insert(fr);
    }


    bool can = false;

    vector<bool> visited (n + 1, 0);

    queue<pair<int,int>> q;
    q.push({a, 0});

    int x, y;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (visited[x]) continue;

        if (x == b) {
            can = true;
            break;
        }
        
        visited[x] = true;

        for (auto i : graph[x]) {
            if(i != y) q.push({i, x});
        }

    }  

    cout << (can ? "YES\n" : "NO\n");

}
