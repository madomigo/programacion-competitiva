#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v (n + 1);
        for (int i = 1; i <= n; i++) 
            cin >> v[i];

        vector<int> dp (n + 1);
        int ans = 0;
        for (int i = n; i > 0; i--) {
            if (v[i] + i > n) dp[i] = v[i];
            else dp[i] = v[i] + dp[i + v[i]];

            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
}