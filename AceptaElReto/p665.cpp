#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    int a1, a2, a3, b1, b2, b3;
    while (t--) {
        cin >> a1;
        getchar();
        cin >> a2; 
        getchar();
        cin >> a3;
        getchar();
        cin >> b1;
        getchar();
        cin >> b2;
        getchar();
        cin >> b3;

        if (a1 != b1) {
            if (b1 == a1 + 1 && b2 == 0 && b3 == 0)
                cout << "SI\n";
            else 
                cout << "NO\n";
            continue;
        }

        if (a2 != b2) {
            if (b2 == a2 + 1 && b3 == 0) 
                cout << "SI\n";
            else 
                cout << "NO\n";
            continue;
        }

        if (b3 == a3 + 1)
            cout << "SI\n";
        else
            cout << "NO\n";

    }
}