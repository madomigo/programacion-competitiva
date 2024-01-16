#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (true) {
        cin >> n;

        if (n == 0) break;

        bool crece = true;
        int anterior;
        cin >> anterior;
        int actual;
        for (int i = 1; i < n; i++) {
            cin >> actual;
            if (actual <= anterior) crece = false;

            anterior = actual;
        }

        cout << (crece ? "SI\n" : "NO\n");
    }
}