#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

int main () {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int f, t;
    vector<set<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> f >> t;
        g[f].insert(t);
        g[t].insert(f);
    }
    
    //BFS A
    queue<int> qa;
    qa.push(a);
    vector<int> da(n + 1, INF);
    da[a] = 0;
    int x;
    while (!qa.empty()) {
        x = qa.front();
        qa.pop();

        for (auto i : g[x]) {
            if (da[i] == INF) {
                da[i] = da[x] + 1;
                qa.push(i);
            }
        }
    }

    //BFS B
    queue<int> qb;
    qb.push(b);
    vector<int> db(n + 1, INF);
    db[b] = 0;
    while (!qb.empty()) {
        x = qb.front();
        qb.pop();

        for (auto i : g[x]) {
            if (db[i] == INF) {
                db[i] = db[x] + 1;
                qb.push(i);
            }
        }
    }

    int s = da[b];
    vector<pair<int,int>> ans;
    //EACH EDGE
    for (int i = 1; i <= n; i++) {
        for (auto j : g[i]) {
            if (j > i && min(da[i] + 1 + db[j], da[j] + 1 + db[i]) == s) ans.push_back({i, j});
        }
    }

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i.first << " " << i.second << '\n';





}