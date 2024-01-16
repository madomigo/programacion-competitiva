#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using namespace std;

using ll = long long;

ll n, m, tTotal;
int main() {
    while (cin >> n >> m >> tTotal) {

        ll h1[n], h2[m];
        for (int i = 0; i < n; i++) {
            cin >> h1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> h2[i];
        }

        ll tiempo = 0, turrones = 0, p1 = n, p2 = m;

        while (p1 > 0 && tiempo + h1[p1 - 1] <= tTotal) {
            p1--;
            tiempo += h1[p1];
            turrones++;
        }
        
        while (p2 > 0 && tiempo + h2[p2 - 1] <= tTotal) {
            p2--;
            tiempo += h2[p2];
            turrones++;
        }

        ll turrMax = turrones;

        while (p1 < n) {
            tiempo -= h1[p1];
            p1++;
            turrones--;
            while (p2 > 0 && tiempo + h2[p2 - 1] <= tTotal) {
                p2--;
                tiempo += h2[p2];
                turrones++;
            }
            turrMax = max(turrMax, turrones);
        }

        cout << turrMax << '\n';
    }
}