#include <iostream>
using namespace std;

int main() {
    int nEquipos, minimo, maximo, personas;
    int validos = 0;
    cin >> nEquipos >> minimo >> maximo;
    for (int i = 0; i < nEquipos; i++) {
        cin >> personas;
        if (personas >= minimo && personas <= maximo) validos++;
    }
    cout << validos << endl;
    return 0;
}