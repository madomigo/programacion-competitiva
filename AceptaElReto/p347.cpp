#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j) {
    if (i < 10 || j < 10) return 0;
    if (i == j) return 1;
    if (i > j) 
        return (i / j) + solve(i - (i/j)*j, j);
    return (j / i) + solve(i, j - (j/i)*i);
}

int main () {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cout << solve(n, m) << '\n';
    }
}