#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, maximo;
        cin >> n >> maximo;
        vector<int> monedas (n);

        int monedaMasAlta = 0;
        for (int i = 0; i < n; i++) {
            cin >> monedas[i];
            monedaMasAlta = max(monedaMasAlta, monedas[i]);
        }
        int mayorPrecio = monedaMasAlta * maximo;

        sort(monedas.begin(), monedas.end());
        vector<pair<bool, int>> dp (mayorPrecio + 1, {false, INT32_MAX});

        int ans = 0;
        dp[0].first = true;
        dp[0].second = 0;
        for (int i = 0; i < mayorPrecio; i++) {
            for (int j = 0; j < n; j++) {
                if (i + monedas[j] > mayorPrecio) break;
                if (dp[i].first == false || dp[i].second >= maximo) break;

                if (dp[i + monedas[j]].first == false) {
                    dp[i + monedas[j]].first = true;
                    dp[i + monedas[j]].second = dp[i].second + 1;
                    ans++;
                }
                else {
                    dp[i + monedas[j]].second = min(dp[i + monedas[j]].second, dp[i].second + 1);
                }
            }
        }
        cout << ans << '\n';

        

        

    }
}