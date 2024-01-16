/**
* Encuesta comprometedora
* Es el ejercicio 583 de Acepta el reto
* @author Mateo Dominguez
* @version 3.12.2021
*/
#include <iostream>
using namespace std;

int main() {
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        long long comprometedora, segunda;
        cin >> comprometedora >> segunda;
        if (comprometedora == 0 && segunda == 0) break;
        long long suma1 = comprometedora + segunda;
        long long resta = comprometedora - (suma1 / 2);
        long long suma2 = resta + segunda;
        long long porcentaje = 100 * resta / suma2;
        
        cout << porcentaje << endl;


    }
}