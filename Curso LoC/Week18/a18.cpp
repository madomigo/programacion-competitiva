#include <bits/stdc++.h>
using namespace std;
#define int long long

int m;
int exp(int a, int b) {
    if (b == 0) return 1 % m;
    if (b % 2 == 1) return exp(a, b - 1) * a % m;
    else {
        int ak = exp(a, b/2);
        return ak * ak % m;
    }
}

int32_t main () {
    int n;
    cin >> n;
    int a, b;
    while (n--) {
        cin >> a >> b >> m;
        cout << exp(a, b) % m << '\n';
    }
    
}