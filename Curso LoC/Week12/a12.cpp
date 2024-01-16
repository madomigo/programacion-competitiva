#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<vector<int>> v (n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (v[i][j] == 1) ans++;
        }
    }

    cout << ans << '\n';
}