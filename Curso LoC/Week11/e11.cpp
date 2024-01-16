#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> dp;
vector<vector<int>> opt;
vector<int> v;
vector<int> ans;

void Solve (int i, int j) {
    if (i < 1 || j < 1)
        return;
    if (opt[i][j] == 0) {
        Solve(i, j - 1);
        return;
    } else if (opt[i][j] == 1) {
        Solve(i - 1, j);
        return;
    } else {
        Solve(i - 1, j - v[i]);
        //cout << "WE TAKE ITEM " << i << endl;
        ans.push_back(i);
        return;
    }
}


int32_t main () {
    int n;
    cin >> n;

    v.resize(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        sum += v[i];
    }

    if (sum % 2 == 1) {
        cout << "NO\n";
        return 0;
    }

    int mid = sum / 2;

    dp.resize(n, vector<int> (mid + 1));
    opt.resize(n, vector<int> (mid + 1));

    for (int j = v[0]; j <= mid; j++) dp[0][j] = v[0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= mid; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

            if (v[i] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + v[i]);

            if (dp[i][j] == dp[i][j - 1]) opt [i][j] = 0;
            else if (dp[i][j] == dp[i - 1][j]) opt[i][j] = 1;
            else opt[i][j] = 2;

            if (dp[i][j] == mid) {
                cout << "YES\n";

                Solve(i, j);

                cout << ans.size() << '\n';

                for (auto k : ans) cout << k << ' ';
                
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "NO\n";


}