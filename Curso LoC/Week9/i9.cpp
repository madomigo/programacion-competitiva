#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int v[1000030];

int Solve(int x) {
    if (x == n) return 1;
    if (x > n) return 0;

    if (v[x + 1] == -1) v[x + 1] = Solve(x + 1) % 1000000007; 

    if (v[x + 2] == -1) v[x + 2] = Solve(x + 2) % 1000000007; 

    if (v[x + 3] == -1) v[x + 3] = Solve(x + 3) % 1000000007; 

    if (v[x + 4] == -1) v[x + 4] = Solve(x + 4) % 1000000007; 

    if (v[x + 5] == -1) v[x + 5] = Solve(x + 5) % 1000000007; 

    if (v[x + 6] == -1) v[x + 6] = Solve(x + 6) % 1000000007; 

    return ((v[x + 1] + v[x + 2] + v[x + 3] + v[x + 4] + v[x + 5] + v[x + 6]) % 1000000007);

}


int32_t main () {
    cin >> n;

    for (int i = 0; i <= n + 15; i++) v[i] = -1;

    cout << Solve(0) << '\n';
}