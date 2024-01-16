#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    int n;
    while (t--) {
        cin >> n;

        vector<int> v (n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int ans = v[0];
        int sum = ans;
        for (int i = 1; i < n; i++) {
            ans = max(ans, v[i] - sum);
            sum += v[i] - sum;
        }

        cout << ans << '\n';
    }

}