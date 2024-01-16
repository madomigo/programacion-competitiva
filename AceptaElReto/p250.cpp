#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        int total = 0;
        vector<int> v (n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            total += v[i];
        }

        int left = v[0], right = total - v[0];
        int dif = abs(right) - abs(left);

        int minimumDif = total;
        int ans = 0;

        for (int k = 0; k < n - 1; k++) {
            right = total - left;
            dif = abs(right) - abs(left);

            if (abs(dif) < abs(minimumDif) && abs(dif) != abs(total)) {
                ans = k + 1;
                minimumDif = abs(dif);
            }
            left += v[k + 1];
        }

        cout << ans << '\n';
    }
}