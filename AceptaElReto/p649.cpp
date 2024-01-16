#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m, t;
    while (cin >> n >> m >> t) {
        priority_queue<pair<pair<int,int>, int>> q;
        int a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            q.push({{-a, -b}, 0});
        } 
        int p;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> p;
            q.push({{-a, -b}, p});
        }
        int prev = -1000;
        bool posible = true;
        while (!q.empty()) {
            a = -q.top().first.first;
            b = -q.top().first.second;
            p = q.top().second;
            q.pop();
            //cout << a << ' ' << b << ' ' << p << ' ' << prev << '\n';

            if (a >= t) break;

            if (a < prev) {
                posible = false;
                break;
            }

            if (p != 0) {
                q.push({{-(a + p), -(b + p)}, p});
            }

            prev = b;
        }

        if (!posible) cout << "SI\n";
        else cout << "NO\n";
    }
}