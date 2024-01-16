#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, W;
    cin >> W >> n;
    vector<int> w (n);
    vector<vector<int>> dp (n, vector<int> (W + 1));
    for (int i = 0; i < n; i++) cin >> w[i];

    for (int i = w[0]; i <= W; i++) dp[0][i] = w[0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

            if (w[i] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
        }
    }
    cout << dp[n - 1][W] << '\n';
}