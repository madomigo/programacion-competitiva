#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

int main () {
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        vector<set<int>> g(n + 1);
        int f,t;
        for (int i = 0; i < m; i++) {
            cin >> f >> t;
            g[f].insert(t);
            g[t].insert(f);
        }
        queue<int> q;
        q.push(1);
        vector<int> d (n + 1, INF);
        d[1] = 0;
        int x;
        while (!q.empty()) {
            x = q.front();
            q.pop();

            for (auto i : g[x]) {
                if (d[i] == INF) {
                    d[i] = d[x] + 1;
                    q.push(i);
                }
            }
        }

        vector<int> odd;
        vector<int> even;
        for (int i = 1; i <= n; i++) {
            if (d[i] % 2 == 0) even.push_back(i);
            else odd.push_back(i);
        }

        if (odd.size() >= even.size()) {
            cout << even.size() << '\n';
            for (auto i : even) cout << i << " "; 
        }
        else {
            cout << odd.size() << '\n';
            for (auto i : odd) cout << i << " ";
        }
        cout << '\n';
    }
}