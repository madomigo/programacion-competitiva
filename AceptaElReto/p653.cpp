#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

int main () {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<int> v (n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        int curr = 0;
        pair<int,int> best;

        for (int i = 1; i <= 10; i++)
            curr += v[i];
        best = {curr, 10};
        for (int i = 11; i <= n; i++) {
            curr -= v[i - 10];
            curr += v[i];
            if (best.first >= curr) {
                best = {curr, i};
            }
        }
        int h = 0;
        while (best.first >= 60) {
            h++;
            best.first -= 60;
        }

        cout << best.second * 100 - 1000 << "-" << best.second * 100 << ' ' << h << ":";
        if (best.first < 10) cout << 0;
        cout << best.first << '\n';
    }

}