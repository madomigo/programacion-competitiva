#include <bits/stdc++.h>
using namespace std;

long long GCD (long long a, long long b) {
    long long ans;
    while (b != 0) {
        ans = b;
        b = a % b;
        a = ans;
    }
    return ans;
}

int main () {
    long long n,n2;
    while (true) {
        cin >> n;
        if (n == 0) break;
        long long ans = 1;
        long long gcd = n;
        long long gcd2;
        while (true) {
            cin >> n2;
            if (n2 == 0) break;

            gcd2 = GCD(gcd, n2);
            if (gcd == gcd2) {
                ans += n2 / gcd;
            }
            else {
                ans *= gcd;
                ans /= gcd2;
                ans += n2 / gcd2;
                gcd = gcd2;
            }
        }

        cout << ans << '\n';
        
    }
}