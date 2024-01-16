#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<int> alturas (n);
        for (int i = 0; i < n; i++) {
            cin >> alturas[i];
        }
        
        vector<int> esquis (n);
        for (int i = 0; i < n; i++) {
            cin >> esquis[i];
        }

        sort(alturas.begin(), alturas.end());
        sort(esquis.begin(), esquis.end());
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(alturas[i] - esquis[i]);
        }

        cout << ans << '\n';
    }
}