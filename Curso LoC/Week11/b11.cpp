#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n), c(n);

    for (int i = 0; i < n; i++) cin >> w[i] >> c[i];

    vector<vector<int>> dp(n, vector<int>(W + 1));

    for (int j = w[0]; j <= W; j++) dp[0][j] = c[0];
 
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= W; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

            if (w[i] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + c[i]);
        }

    cout << dp[n - 1][W];
}