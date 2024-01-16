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


    bool can = false;

    vector<bool> visited (n + 1, 0);
    vector<int> ans (n + 1);

    queue<pair<int,int>> q;
    int elem;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        elem = 0;
        vector<int> els;

        q.push({i, 0});

        int x, y;
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            if (visited[x]) continue;
            els.push_back(x);
            elem++;


            
            visited[x] = true;

            for (auto i : graph[x]) {
                if(i != y) q.push({i, x});
            }
        }


        for (auto el : els) ans[el] = elem;
    }  

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

}
