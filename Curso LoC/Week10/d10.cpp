#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int dp[100005];
int Solve(int x) {
    if (x == n) return 1;
    if (x > n) return 0;

    if (dp[x + 1] == -1) dp[x + 1] = Solve(x + 1);
    if (dp[x + 2] == -1) dp[x + 2] = Solve(x + 2);

    return ((dp[x + 1] + dp[x + 2]) % 1000000007);
}

int32_t main () {
    cin >> n;   

    for(int i = 0; i <= n + 3; i++) dp[i] = -1;

    cout << Solve(0) << '\n';

}