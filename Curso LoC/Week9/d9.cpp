#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> v(n + 1, INT32_MAX);

    v[0] = 0;
    v[1] = 0;
    if (n >= 2) v[2] = 1;
    for (int i = 3; i <= n; i++) {
        if (i % 3 == 0) v[i] = min(v[i], v[i / 3] + 1);

        if (i % 2 == 0) v[i] = min(v[i], v[i / 2] + 1);

        v[i] = min(v[i], v[i - 1] + 1);
    }

    cout << v[n] << '\n';
}