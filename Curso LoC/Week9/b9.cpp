#include <bits/stdc++.h>
using namespace std;

int n, m;
int table[500][500];
int v[500][500];


int main () {
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                v[i][j] = table[i][j];
                continue;
            }

            if (i == 0) {
                v[i][j] = v[i][j - 1] + table[i][j];
                continue;
            }

            if (j == 0) {
                v[i][j] = v[i - 1][j] + table[i][j];
                continue;
            }

            v[i][j] = max(v[i - 1][j], v[i][j - 1]) + table[i][j];
        }
    }
    
    cout << v[n - 1][m - 1] << "\n";
    
}