#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    int h, m;
    while (t--) {
        cin >> h;
        getchar();
        cin >> m;
        m = 60 - m;
        if (m == 60) m = 0;
        h = 12 - h;
        if (m > 0) h--;
        h = (h + 12) % 12;
        if (h == 0) h = 12;

        if (h < 10) cout << 0;
        cout << h << ":";
        if (m < 10) cout << 0;
        cout << m << '\n';
    }
}