#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;

        if (n == 0) break;

        int numeros[n];

        for (int i = 0; i < n; i++) {
            cin >> numeros[i];
        }

        sort(numeros, numeros + n);

        if (n % 2 == 1) {
            cout << numeros[(n - 1) / 2] * 2 << "\n";
        }
        else {
            cout << numeros[(n - 1) / 2] + numeros[((n - 1) / 2) + 1] << "\n"; 
        }
    }
}