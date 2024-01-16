#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n;
    cin >> n;

    int it = 1000000;
    double ec;
    double low = -1, high = n + 1, mid;

    while (it--) {
        mid = (high + low) / 2;

        ec = mid*(42*mid*mid + 13*mid + 1337);
        if (ec < n) low = mid;
        else if (ec > n) high = mid;
        else break;
    }

    cout << setprecision(16) << mid << "\n";

}