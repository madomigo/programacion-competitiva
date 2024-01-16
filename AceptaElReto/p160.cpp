#include <iostream>
using namespace std;

int main () {
    int n;
    while(true) {
        cin >> n;
        if (n == 0) break;

        int matriz[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matriz[i][j];
            }
        }

        bool sePuedeAbajo = true;

        for (int j = 0; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                if (matriz[i][j] != 0) sePuedeAbajo = false;
            }
        }

        bool sePuedeArriba = true;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (matriz[i][j] != 0) sePuedeArriba = false;
            }
        }

        cout << (sePuedeAbajo || sePuedeArriba ? "SI\n" : "NO\n");
    }
}