#include <iostream>
#include <array>
using namespace std;

int main () {
    while (true) {
        int racimos, uvas, uvasRac, lleva, minimo, contador;
        lleva = minimo = contador = 0;
        cin >> racimos >> uvas;
        if (racimos == 0 && uvas == 0) break;
        int camino[racimos];
        
        // miro cada racimo
        for (int i = 0; i < racimos; i++) {
            cin >> uvasRac;
            camino[i] = uvasRac;
            
            lleva += uvasRac;
            if (lleva < uvas) continue;
            while (lleva - camino[contador] >= uvas) {
                lleva -= camino[contador];
                contador++;
            }
            if (minimo > lleva || minimo == 0) minimo = lleva;
           
        }
        if (minimo != 0) cout << minimo << endl;
        else cout << "IMPOSIBLE" << endl;

    }
}