#include <bits/stdc++.h>
using namespace std;

int main () {
    int d, vMx, t;
    while (true) {
        cin >> d >> vMx >> t;
        if (d == 0 && vMx == 0 && t == 0) break;
        if (d <= 0 || vMx <= 0 || t <= 0) {
            cout << "ERROR\n";
            continue;
        }
        double v = 3.6 * d / t;
        if (v <= vMx) cout << "OK\n";
        else if (v >= vMx * 1.2) cout << "PUNTOS\n";
        else cout << "MULTA\n";
    }
}