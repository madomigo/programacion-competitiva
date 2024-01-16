#include <iostream>
using namespace std;

int main() {
    int nSonidos;
    while (true) {
        cin >> nSonidos;

        if (nSonidos == 0) break;

        int marc1, marc2;
        marc1 = marc2 = 0;

        string sonido;

        bool derecha = true;

        for (int i = 0; i < nSonidos; i++) {
            cin >> sonido;

            if (sonido == "PIC") {
                if (derecha) derecha = false;
                else derecha = true;
            }
            if (sonido == "PONG!") {
                if (derecha) marc1++;
                else marc2++;
            }
        }

        cout << marc1 << " " << marc2 << "\n";
    }
}