#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int tamano, nAnillos, minimo, minimo2, minimo3, t;
    while (cin >> tamano) {
        t = tamano;
        nAnillos = 0;
        while (t > 0) {
            t -= 2;
            nAnillos++;
        }
        long long grosor;
        vector<long long> anillos;

        for (int i = 0; i < tamano; i++) {
            
        
            for (int j = 0; j < tamano; j++) {
                cin >> grosor;
                minimo2 = min(j, tamano - 1 - j);
                minimo3 = min (i, tamano - 1 - i);
                minimo = min(minimo2, minimo3);

                if (j == i && j < nAnillos) {
                    anillos.push_back(grosor);
                }
                else {
                    anillos[minimo] += grosor;
                }

            }
        }
        for (int i = nAnillos - 1; i > 0; i--) {
            cout << anillos[i] << " ";
        }
        cout << anillos[0] << endl;
    }
}