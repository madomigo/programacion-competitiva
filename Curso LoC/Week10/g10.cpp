#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    
    if (n % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<vector<int>> dp (n + 1, vector<int> (2 * n + 1));

    dp[0][n] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            if (j == 0) dp[i][j] = dp[i - 1][j + 1];
            else if (j == 2 * n) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000007;
        }
    }

    cout << dp[n][n] << '\n';
}