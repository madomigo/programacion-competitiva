#include <bits/stdc++.h>
using namespace std;

int main () {
    int a, b, c, n;
    while (true) {
        cin >> a >> b >> n;
        if (a == 0 && b == 0 && n == 0) break;
        if (n == 0) {
            cout << a << '\n';
            continue;
        }
        else if (n == 1) {
            cout << b << '\n';
            continue;
        }
        n++;
        
        if (n % 6 == 0) cout << a-b << '\n';
        else if (n % 6 == 1) cout << a << '\n';
        else if (n % 6 == 2) cout << b << '\n'; 
        else if (n % 6 == 3) cout << b - a << '\n';
        else if (n % 6 == 4) cout << -a << '\n';
        else if (n % 6 == 5) cout << -b << '\n';
    }
}