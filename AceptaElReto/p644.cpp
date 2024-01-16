#include <bits/stdc++.h>
using namespace std;


int main () {
    int year;
    while (true) {
        cin >> year;
        if (year == 0) break;
        int m = 24, n = 5;
        int a = year %  19;
        int b = year % 4;
        int c = year % 7;;
        int d = (19 * a + m) % 30;
        int e = (2 * b + 4 * c + 6 * d + n) % 7;
        
        if (d + e < 10) cout << d + e + 22 << " de marzo\n";
        else {
            int ans = d + e - 9;
            if (ans == 26) ans = 19;
            else if (ans == 25 && d == 28) ans = 18;
            cout << ans << " de abril\n";
        }
    }
    
}