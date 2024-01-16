#include <bits/stdc++.h>
using namespace std;
#define N 100003

vector<long long> v (N);
vector<long long> dp (N);

int main () {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            dp[i] = -1;
        }
        
        for (int i = 1; i <= k + 1; i++) {
            dp[i] = max(dp[i-1], v[i]);
        }
        for (int i = k + 2; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i - k - 1] + v[i]);
        }

        cout << dp[n] << '\n';

    }
}