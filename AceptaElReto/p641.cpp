#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    int k, n;
    while (true) {
        cin >> k >> n;
        if (k == 0 && n == 0) break;
        vector<int> v (n);
        int sum = 0;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        for (int i = 0; i < k; i++) 
            sum += v[i];
        int ans = sum;

        for (int i = 0; i < n - k; i++) {
            sum -= v[i];
            sum += v[i + k];
            ans = max(ans, sum);
            //cout << ans << '\n';
        }

        cout << ans << '\n';
    }
}