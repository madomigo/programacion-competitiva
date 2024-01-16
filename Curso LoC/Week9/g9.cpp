#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int v[40];

int Solve (int x) {
    if (x - 1 == n) return 1;
    if (x - 1 > n) return 0;

    if (v[x + 1] == -1) v[x + 1] = Solve(x + 1); 

    if (v[x + 2] == -1) v[x + 2] = Solve(x + 2) * 2; 

    if (v[x + 3] == -1) v[x + 3] = Solve(x + 3) * 5; 

    return (v[x + 1] + v[x + 2] + v[x + 3]);
}

int32_t main() {

    cin >> n;

    for (int i = 0; i <= n + 4; i++) v[i] = -1;

    cout << Solve(0) << '\n';



}