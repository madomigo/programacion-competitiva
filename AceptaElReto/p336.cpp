#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int alumnos;
    while (cin >> alumnos) {
        int pesos[alumnos];
        int suma1 = 0;
        for (int i = 0; i < alumnos; i++) {
            cin >> pesos[i];
            suma1 += pesos[i];
        }

        int suma2 = 0;
        int mejor = INT32_MAX;
        bool puede = true;
        int izq = 0;
        int der = 0;
        int equipo1 = 0;

        for (int i = 0; i < alumnos; i++) {
            suma1 -= pesos[i];
            suma2 += pesos[i];

            if (abs(suma2 - suma1) == mejor) {
                puede = false;
                break;
            }
            else if (abs(suma2 - suma1) < mejor) {
                mejor = abs(suma2 - suma1);
                izq = suma2;
                der = suma1;
                equipo1++;

            }
        }

        if (puede) cout << equipo1 << " " << izq << " " << der << "\n";
        else cout << "NO JUEGAN\n";

    }
}