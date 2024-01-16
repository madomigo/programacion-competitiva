#include <bits/stdc++.h>	
using namespace std;
#define int long long

int32_t main () {
    int d, n;
    while (true) {
        cin >> d >> n;
        if (d == 0 && n == 0) break;

        if (n == 0 && d <= 4) {
            cout << d << '\n';
            continue;
        }
        else if (n == 0) {
            cout << "NINGUNO\n";
            continue;
        }
        
        int ans;
        int l, r, mid;
        l = 1;
        r = 100000000000000000;
        int sumando, sum;
        while (l < r) {
            mid = (l + r) / 2;
            sum = 0;
            sumando = mid / 5;
            while (sumando != 0) {
                sum += sumando;
                sumando /= 5;
            }

            if (sum == n) break;

            if (sum < n) {
                l = mid + 1;
            }

            else {
                r = mid;
            }
        }
        
        if (sum != n) {
            cout << "NINGUNO\n";
            continue;
        }

        if (mid % 10 >= 5) ans = mid - mid % 10 + 5;
        else 
            ans = mid - mid % 10;
        bool solucion = false;
        for (int i = 1; i <= 5; i++) {
            if (ans % d == 0) {
                cout << ans << '\n';
                solucion = true;
                break;
            }
            ans++;
        }

        if (!solucion) {
            cout << "NINGUNO\n";
        }

    }
}