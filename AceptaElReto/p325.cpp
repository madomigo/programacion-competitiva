#include <iostream>
#include <string>
using namespace std;

string combHelados(int choco, int vainilla, string helados) {
    string cadena;

    if (choco == 0) {
        cadena = helados;
        for (int i = 0; i < vainilla; i++) {
            cadena += 'V';
        }
        cadena += ' ';
    }

    else if (vainilla == 0) {
        cadena = helados;
        for (int i = 0; i < choco; i++) {
            cadena += 'C';
        }
        cadena += ' ';
    }

    else {
        cadena += combHelados(choco - 1, vainilla, helados + 'C');
        cadena += combHelados(choco, vainilla - 1, helados + 'V');
    }
    
    return cadena;
}

int main() {
    int nCasos;
    cin >> nCasos;

    for (int i = 0; i < nCasos; i++) {
        int choco, vainilla;
        cin >> choco >> vainilla;

        string helados = combHelados(choco, vainilla, "");
        helados.pop_back();

        cout << helados << '\n';
    }
}