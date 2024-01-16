#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<set<int>> graph;
vector<bool> visited;
vector<int> p;
int n, a, b;


void dfs (int x, int parent) {
    //cout << x << " " << parent << '\n';

    if (visited[x]) return;
    visited[x] = true;
    p[x] = parent;

    for (auto i : graph[x]){
        if (!visited[i]) {
            dfs (i, x);
        }

    }
}

int main() {
    cin >> n >> a >> b;
    int num;

    graph.resize(n + 1);
    visited.resize(n + 1);
    p.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;

            if (num == 1) {
                graph[i].insert(j);
            }
        }
    }

    dfs (a, -1);

    if (visited[b] == 0) cout << -1 << '\n';
    else {
        vector<int> ans;
        int x = b;
        while(x != a) {
            if (x == -1) break;
            ans.push_back(x);
            x = p[x];
        }
        
        cout << ans.size() << '\n';

        ans.push_back(a);

        for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";

        cout << '\n';

    }

 
}