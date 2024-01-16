#include <bits/stdc++.h>
using namespace std;
#define int long long

int v[100005];
int n;

int Solve (int x) {
    if (x - 1 == n) return 1;
    if (x - 1 > n) return 0;

    if (v[x + 1] == -1) v[x + 1] = Solve(x + 1); 

    if (v[x + 2] == -1) v[x + 2] = Solve(x + 2); 

    if (v[x + 3] == -1) v[x + 3] = Solve(x + 3); 

    return ((v[x + 1] + v[x + 2] + v[x + 3]) % 1000000007);
}


int32_t main () {

    cin >> n;

    for(int i = 0; i <= n + 5; i++) v[i] = -1;

    cout << Solve(0) << '\n';

}