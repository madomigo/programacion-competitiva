#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using namespace std;


struct Ascensor {
    int inicial, final, nivel;
};

Ascensor ascensores[100000];

/* Metodo para ordenar los ascensores: Primero segun su punto inicial, luego segun su nivel, y finalmente segun su punto final */
bool compararAscensor (Ascensor a1, Ascensor a2) {
    if (a1.final < a2.final) return 1;
    return 0;
}



void imprimeAscensores(int nAsc) {
    for (int i = 0; i < nAsc; i++) {
        cout << ascensores[i].inicial << ' ' << ascensores[i].final << ' ' << ascensores[i].nivel << '\n';
    }
}


int nAscensores;
int ultPlanta;

bool esPosible (int nivel) {
    int pos = 0;

    for (int i = 0; i < nAscensores; i++) {
        if (ascensores[i].nivel <= nivel && ascensores[i].inicial <= pos && ascensores[i].final > pos) {
            pos = ascensores[i].final;
        }
    }

    return (pos == ultPlanta);
}


int main() {
    while (cin >> nAscensores) {
        ultPlanta = 0;

        /* Recogemos y almacenamos las entradas */
        for (int i = 0 ; i < nAscensores; i++) {
            cin >> ascensores[i].inicial >> ascensores[i].final >> ascensores[i].nivel;

            ultPlanta = max(ultPlanta, ascensores[i].final);
        }

        /* Ordenamos los ascensores, segun nuestro metodo */
        sort(ascensores, ascensores + nAscensores, compararAscensor);

        int bajo = 1, alto = 1000001, mitad;
        while (alto > bajo) {
            mitad = (alto + bajo) / 2;
            if (!esPosible(mitad)) bajo = mitad + 1;
            else alto = mitad;
        }

        cout << bajo << '\n';
    }
}