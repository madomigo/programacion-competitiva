#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int s;
    map<int, int> fac;
    while (n--) {
        cin >> s;
        for (int i = 2; i * i <= s; i++) {
            if (s % i == 0) fac[i]++;
            while (s % i == 0) s /= i;
        }
        if (s > 1) fac[s]++;
    }
    int ans = 1;
    for (auto i : fac)
        ans = max(ans, i.second);
    cout << ans << '\n';
}
