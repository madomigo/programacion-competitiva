#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[51][51];

int Solve (int x, int y) {
    if (x == n && y == m) return 1;

    int ans = 0;

    if (x + 2 <= n && y + 1 <= m) {
        if (v[x + 2][y + 1] == -1) v[x + 2][y + 1] = Solve(x + 2, y + 1);
        ans += v[x + 2][y + 1]; 
    }

    if (x + 1 <= n && y + 2 <= m) {
        if (v[x + 1][y + 2] == -1) v[x + 1][y + 2] = Solve(x + 1, y + 2);
        ans += v[x + 1][y + 2];
    }

    if (x - 1 >= 1 && y + 2 <= m) {
        if (v[x - 1][y + 2] == -1) v[x - 1][y + 2] = Solve(x - 1, y + 2);
        ans += v[x - 1][y + 2]; 
    }

    if (x + 2 <= n && y - 1 >= 1) {
        if (v[x + 2][y - 1] == -1) v[x + 2][y - 1] = Solve(x + 2, y - 1);
        ans += v[x + 2][y - 1]; 
    }

    return ans;
}

int main () {

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            v[i][j] = -1;
        }
    }

    cout << Solve(1, 1) << '\n';
    
}