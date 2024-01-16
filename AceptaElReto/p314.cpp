#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        int a,b,c;
        if (n < 3) {
            for (int i = 0; i < n; i++)
                cin >> a;
            cout << 0 << ' ' << 0 << '\n';  
            continue;
        } 
        int picos = 0, valles = 0;
        cin >> a >> b;
        for (int i = 2; i < n; i++) {
            cin >> c;
            if (a > b && c > b) valles++;
            else if (a < b && c < b) picos++;

            a = b;
            b = c;
        }

        cout << picos << ' ' << valles << '\n';
    }
}