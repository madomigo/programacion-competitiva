#include <iostream>
using namespace std;

int main() {
    long long numCasos, horas, encendidos, horasUso;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        cin >> horas >> encendidos >> horasUso;
        if (horas / encendidos == horasUso && horasUso * encendidos >= horas) {
            cout << "AMBAS" << endl;
        }
        else if (encendidos * horasUso >= horas) {
            cout << "HORAS" << endl;
        }
        else {
            cout << "ENCENDIDOS" << endl;
        }
    }
}