#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k;
    cin >> n >> k;

    int base = n;
    int ans = 0;
    int suma = 0;

    if (k == 1) {
        cout << 1 << '\n';
        return 0;
    }

    while (suma <= n) {
        if (base == 1) {
            ans += n - suma;
            break;
        }
        
        while (suma + pow(base, k) <= n) {
            ans++;
            suma += pow(base, k);
            //cout << "mas " << base << " " << suma << '\n';
        }
        base--;
    }


    cout << ans << '\n';

}