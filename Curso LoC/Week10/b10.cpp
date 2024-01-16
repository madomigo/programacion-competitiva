#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<int> v (n);
    vector<int> dp (n);

    if (n == 1) {
        cin >> v[0];
        cout << v[0] << '\n';
        return 0;
    }

    cin >> v[0] >> v[1];

    dp[0] = v[0];
    dp[1] = max(v[0] + v[1], 2 * v[1]);

    for (int i = 2; i < n; i++) {
        cin >> v[i];
        dp[i] = max(v[i] + dp[i - 1], 2 * v[i] + dp[i - 2]);
    }

    cout << dp[n - 1] << '\n';

    
}