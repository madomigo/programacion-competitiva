#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main () {
    int n;
    cin >> n;
    int energy[n];

    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }

    int v[n];

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            v[i] = 0;
            continue;
        }

        if (i == 1) {
            v[i] = abs(energy[i - 1] - energy[i]);
            continue;
        }

        v[i] = min(abs(energy[i - 1] - energy[i]) + v[i - 1], abs(3 * (energy[i - 2] - energy[i])) + v[i - 2]);
    
    }

    cout << v[n - 1] << '\n';
}