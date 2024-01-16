#include <iostream>
#include <array>

using namespace std;

int main() {
    int filas, columnas;
    while (true) {
        cin >> filas >> columnas;
        if (filas == 0 && columnas == 0) break;

        int minimosFilas[filas], maximosFilas[filas], minimosColumnas[columnas], maximosColumnas[columnas];
        for (int i = 0; i < columnas; i++) {
            minimosColumnas[i] = 2147483647;
            maximosColumnas[i] = -2147483648;
        }

        for (int i = 0; i < filas; i++) {
            minimosFilas[i] = 2147483647;
            maximosFilas[i] = -2147483648;
        }

        int tablero[filas][columnas];
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cin >> tablero[i][j];
                if (tablero[i][j] > maximosFilas[i]) maximosFilas[i] = tablero[i][j];
                if (tablero[i][j] > maximosColumnas[j]) maximosColumnas[j] = tablero[i][j];
                if (tablero[i][j] < minimosFilas[i]) minimosFilas[i] = tablero[i][j];
                if (tablero[i][j] < minimosColumnas[j]) minimosColumnas[j] = tablero[i][j];
            }
        }

        bool posible = false;
        for (int i = 0; i < filas && !posible; i++) {
            for (int j = 0; j < columnas && !posible; j++) {
                if ((tablero[i][j] == maximosFilas[i] && tablero[i][j] == minimosColumnas[j]) || (tablero[i][j] == maximosColumnas[j] && tablero[i][j] == minimosFilas[i])) posible = true;
            }
        }

        if (posible) cout << "SI\n";
        else cout << "NO\n";
    }
}