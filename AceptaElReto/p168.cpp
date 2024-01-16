#include <iostream>
using namespace std;

int main () {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        int pieza;
        bool visitados[n + 1];
        visitados[0] = true;

        for (int i = 1; i <= n; i++) visitados[i] = false;

        for (int i = 1; i < n; i++) {
            cin >> pieza;
            visitados[pieza] = true;
        }

        for (int i = 1; i <= n; i++) {
            if (!visitados[i]) {
                cout << i << "\n";
                break;
            }
        }
    }
}