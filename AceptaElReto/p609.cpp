#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int tamano, torres;
    while (cin >> tamano >> torres) {
        vector<int> filas;
        vector<int> columnas;
        int fila, col;
        for (int i = 0; i < torres; i++) {
            cin >> fila;
            filas.push_back(fila);

            cin >> col;
            columnas.push_back(col);
        }

        sort(filas.begin(), filas.end());
        sort(columnas.begin(), columnas.end());

        cout << filas[(torres - 1) / 2] << " " << columnas[(torres - 1) / 2] << endl;

    }
}