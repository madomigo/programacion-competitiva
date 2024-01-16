#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;

    while (true) {
        cin >> n;

        if (n == 0) break;

        long long numParejas = 0;
        long long suma = 0;

        int paises[n];
        for (int i = 0; i < n; i++) {
            cin >> paises[i];
            suma += paises[i];
        }

        for (int i = 0; i < n; i++) {
            suma -= paises[i];
            numParejas += suma * paises[i];

            if (suma == 0) break;
        }

        cout << numParejas << "\n";

    }
}