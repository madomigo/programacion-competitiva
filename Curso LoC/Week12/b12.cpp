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

    bool can = true;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (v[i][j] != v[j][i]) {
                can = false;
                goto here;
            }
        }
    }
    here:
    
    if (can) cout << "NO\n";
    else cout << "YES\n";
}