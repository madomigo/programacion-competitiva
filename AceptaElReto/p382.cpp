#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int l, n;
        cin >> l >> n;
        int pos, rad, cub = 0;
        for (int i = 0; i < n; i++) {
            cin >> pos >> rad;
            if (pos - rad <= cub) {
                cub = max(cub, pos + rad);
            }
        }

        if (cub >= l) cout << "SI\n";
        else cout << "NO\n";
    }
}