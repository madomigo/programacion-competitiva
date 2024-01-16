#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, b;
        cin >> a;
        int mx = a;
        int ans = INT32_MIN;
        for (int i = 1; i < n; i++) {
            cin >> b;
            ans = max(ans, mx - b);
            a = b;
            mx = max(mx, a);
        }
        cout << ans << '\n';
    }
}