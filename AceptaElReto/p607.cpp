#include <iostream>
using namespace std;

int main() {
    int nCasos;
    cin >> nCasos;

    for (int i = 0; i < nCasos; i++) {
        int copias, suma, lineas;
        suma = 0;
        lineas = 1;
        cin >> copias;

        while (lineas < copias) {
            suma++;
            lineas *= 2;
        }
        cout << suma << endl;



    }
}