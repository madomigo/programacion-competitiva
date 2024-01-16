#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
    
vector<int> divi (1e6 + 1, -1);
map<int, int> m;

void factorization(int n) {
    int initial = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            m[p] += cnt;
        }
    }
    if (n > 1)
        m[n]++;
}

int32_t main () {
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        factorization(x);
        
    }
    int ans = 1;
    for (auto i : m) {
        ans *= (i.second + 1);
        ans %= MOD;
    }
    
    cout << ans << '\n';
}