#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <limits>
#include <queue>
#include <map>
using namespace std;



int main () {
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; i++) {
        int piezas;
        cin >> piezas;


        int espumillon[piezas];

        for (int i = 0; i < piezas; i++) {
            cin >> espumillon[i];
        }

        if (piezas < 3) {
            cout << "NO HAY NINGUNO\n";
            continue;
        }

        sort(espumillon, espumillon + piezas);

        int perimetro = 0;

        bool sePuede = false;

        for(int i = piezas - 1; i >= 2; i--) {
            if (espumillon[i - 2] + espumillon[i - 1] > espumillon[i]) {

                perimetro = espumillon[i - 2] + espumillon[i - 1] + espumillon[i];
                sePuede = true;
                break;
            }
        }

        if (sePuede) {
            cout << perimetro << "\n";
        }
        else {
            cout << "NO HAY NINGUNO\n";
        }
    }
}