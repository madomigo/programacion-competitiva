#include <bits/stdc++.h>
using namespace std;

long long n;

bool is_prime(int x) {
    if (x == 1) 
        return 0;
    for (int a = 2; a * a <= x; a++) {
        if (x % a == 0)
            return 0;
    }
    return 1;
}


int32_t main () {
    int q;
    cin >> q;
    while(q--) {
        cin >> n;
        int x = sqrt(n);
        if ((long long)x * x == n && is_prime(x)) cout << "YES\n";
        else cout << "NO\n";
    }

}