#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2e18 + 1;
int32_t main () {
    int n, a, b;
    cin >> n >> a >> b;
    queue<int> q;
    vector<int> d(n + 1, INF);
    vector<int> p(n + 1, -1);
    q.push(a);
    d[a] = 0;
    int x;
    while (!q.empty()) {
        x = q.front();
        q.pop();

        int n1 = (x+1) % n;
        int n2 = (x*x+1)%n;
        int n3 = (x*x*x+1)%n;

        if (d[n1] == INF) {
            d[n1] = min(d[n1], d[x] + 1);
            p[n1] = x;
            q.push(n1);
        }

        if (d[n2] == INF) {
            d[n2] = min(d[n2], d[x] + 1);
            p[n2] = x;
            q.push(n2);
        }
        if (d[n3] == INF) {
            d[n3] = min(d[n3], d[x] + 1);
            p[n3] = x;
            q.push(n3);
        }
    }

    if (d[b] == INF) cout << -1;
    else cout << d[b] << '\n'; 

    vector<int> ans;
    int pp = p[b];
    while (pp != -1) {
        ans.push_back(pp);
        pp = p[pp];
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << b << '\n';
}