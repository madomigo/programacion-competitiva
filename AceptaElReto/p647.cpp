#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v (n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> dp (n);
        dp[0] = 1;
        int l = 0;
        int ans = 1;
        map<int, bool> m;
        m[v[0]] = true;
        for (int i = 1; i < n; i++) {
            if (!m[v[i]]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                for (int j = l; j < i; j++) {
                    m[v[j]] = false;
                    if (v[j] == v[i]) {
                        dp[i] = i - j;
                        l = j + 1;
                        break;
                    }
                }
            }
            ans = max(ans, dp[i]);
            m[v[i]] = true;
        }
        cout << ans << '\n';
    }
}