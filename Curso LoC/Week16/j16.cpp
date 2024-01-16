#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main () {
    int x, k, n;
    cin >> x >> k >> n;
    int d[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    priority_queue<int> q;
    q.push(-x);
    bool can = false;
    int f = 1e9 + 1;
    while (f--) {
        x = -q.top();
        q.pop();
        if (x % k == 0) {
            can = true;
            break;
        }
        for (int i = 1; i <= n; i++)
            q.push(-(x * 10 + d[i]));
    }

    if (can) cout << x << '\n';
    else cout << -1 << '\n';
}