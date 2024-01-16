    #include <bits/stdc++.h>
    using namespace std;
    #define int long long

    char v[501][501];
    int dp[501][501];
    int n, m;

    int Solve (int x, int y) {
        if (v[x][y] == '#') return 0;
        if (x == n && y == m) return 1;

        int n1 = 0;
        if (x + 1 <= n) {
            if (dp[x + 1][y] == -1) {
                dp[x + 1][y] = Solve(x + 1, y) % 1000000007;
            }
            
            n1 = dp[x + 1][y];
        } 

        int n2 = 0;
        if (y + 1 <= m) {
            if (dp[x][y + 1] == -1) {
                dp[x][y + 1] = Solve(x, y + 1) % 1000000007;
            }
            
            n2 = dp[x][y + 1];
        } 


        return ((n1 + n2) % 1000000007);
    }

    int32_t main () {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> v[i][j];
                dp[i][j] = -1;
            }
        }


        cout << Solve(1, 1) << '\n';
    }