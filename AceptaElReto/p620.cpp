#include <iostream>
using namespace std;

int cara, numJuegos;
int juegos[8];

bool VueltaAtras(int numJuego, int ocupado1, int ocupado2) {

    if (numJuego == numJuegos && ocupado1 <= cara && ocupado2 <= cara) {
        return true;
    }

    if (ocupado1 > cara || ocupado2 > cara) {
        return false;
    }

   return VueltaAtras(numJuego + 1, ocupado1 + juegos[numJuego], ocupado2)
   || VueltaAtras(numJuego + 1, ocupado1, ocupado2 + juegos[numJuego]);


}

int main () {
    while (cin >> cara >> numJuegos) {
        for (int i = 0; i < numJuegos; i++) {
            cin >> juegos[i];
        }

        if (VueltaAtras(0, 0, 0)) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }
    }
}