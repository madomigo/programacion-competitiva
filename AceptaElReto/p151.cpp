#include <iostream>
using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;

        if (n == 0) break;

        int matriz[n][n];

        bool sePuede = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matriz[i][j];

                if (i == j && matriz[i][j] != 1) sePuede = false;
                else if (i != j && matriz[i][j] != 0) sePuede = false;
            }
        }
        
        cout << (sePuede ? "SI\n" : "NO\n");
    }
}