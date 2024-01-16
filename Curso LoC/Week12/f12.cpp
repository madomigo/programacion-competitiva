#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<set<int>> graph (n + 1);
    int fr, to;
    for (int i = 0; i < m; i++) {
        cin >> fr >> to;
        graph[fr].insert(to);
        graph[to].insert(fr);
    }


    bool tree = true;

    vector<bool> visited (n + 1);
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }

    queue<pair<int,int>> q;
    q.push({1, 0});

    int x, y;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        //cout << x << " ";
        if (visited[x]) {
            tree = false;
            //cout << x << "\n";
            break;
        }
        
        visited[x] = true;

        for (auto i : graph[x]) {
            if(i != y) q.push({i, x});
            //cout << "anado: " << i << '\n';
        }

    }  

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            tree = false;
            break;
        }
    }

    cout << (tree ? "YES\n" : "NO\n");

}
