#include <iostream>
#include <math.h>
using namespace std;

int main () {
    int numCasos;
    double manilla1, manilla2;
    double horas, minutos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        cin >> manilla1 >> manilla2;
        double anguloExtra = manilla2 / 12;
        horas = ((manilla1 * 12) / 360) - anguloExtra / 30;
        minutos = ((manilla2 * 60) / 360);
        if (horas == floor(horas) && minutos == floor(minutos)) {
            if (horas > 9) cout << horas;
            else cout << "0" << horas;
            cout << ":";
            if (minutos > 9) cout << minutos;
            else cout << "0" << minutos;
            cout << endl;
            continue;
        }
        anguloExtra = manilla1 / 12;
        horas = ((manilla2 * 12) / 360) - anguloExtra / 30;
        minutos = ((manilla1 * 60) / 360);
        if (horas == floor(horas) && minutos == floor(minutos)) {
            if (horas > 9) cout << horas;
            else cout << "0" << horas;
            cout << ":";
            if (minutos > 9) cout << minutos;
            else cout << "0" << minutos;
            cout << endl;
            continue;
        }
        cout << "ERROR" << endl;
    }
}