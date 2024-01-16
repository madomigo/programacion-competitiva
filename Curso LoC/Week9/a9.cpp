#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
vector<int> v;

int Solve(int p) {
    if (p == n) return 1;
    
    int ans = 0;

    for (int i = 1; i <= k && p + i <= n; i++) {
        if (v[p + i] == -1) {
            v[p + i] = Solve(p + 1);
            v[p + i] %= 1000000007;
            ans += v[p + i];
        }
        else ans += v[p + i];
    }

    return ans;
}

int32_t main () {
    cin >> n >> k;

    v.resize(n + 1);

    v[0] = v[1] = 0;

    for (int i = 2; i <= n; i++) v[i] = -1;

    cout << Solve(1) % 1000000007 << "\n";
}