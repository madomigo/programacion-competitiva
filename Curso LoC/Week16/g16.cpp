#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int INF = 1e9 + 1;

int n, m, a, b, c;
vector<set<int>> g(N);
vector<int> da(N, -1);
vector<int> db(N, -1);
vector<int> dc(N, -1);


int main(){
    cin >> n >> m >> a >> b >> c;
    while (m--) {
        int f, t;
        cin >> f >> t;
        g[f].insert(t);
        g[t].insert(f);
    }
    //BFS A
    queue<int> qa;
    qa.push(a);
    da[a] = 0;
    while (!qa.empty()) {
        int x = qa.front();
        qa.pop();

        for (auto i : g[x]) {
            if (da[i] == -1) {
                da[i] = da[x] + 1;
                qa.push(i);
            }
        }
    }

    //BFS B
    queue<int> qb;
    qb.push(b);
    db[b] = 0;
    while (!qb.empty()) {
        int x = qb.front();
        qb.pop();

        for (auto i : g[x]) {
            if (db[i] == -1) {
                db[i] = db[x] + 1;
                qb.push(i);
            }
        }
    }

    //BFS C
    queue<int> qc;
    qc.push(c);
    dc[c] = 0;
    while (!qc.empty()) {
        int x = qc.front();
        qc.pop();

        for (auto i : g[x]) {
            if (dc[i] == -1) {
                dc[i] = dc[x] + 1;
                qc.push(i);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, da[i] + db[i] + dc[i]);
    }
    cout << ans << '\n';
}