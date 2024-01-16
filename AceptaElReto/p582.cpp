/**
* ¡Son los cuartos
* Es el ejercicio 582 de Acepta el reto
* @author Mateo Dominguez
* @version 3.12.2021
*/
#include <iostream>
#include <string>
using namespace std;

int main () {
    int numCasos;
    cin >> numCasos;
    string cadena;
    getline(cin, cadena);

    for (int i = 0; i < numCasos; i++) {
        getline(cin, cadena);
        if (cadena == "") {
            cout << "MARISA NARANJO" << endl;
            continue;
        }
        int numEspacios = 0;
        for (int i = 0; i < cadena.length(); i++) {
            if (cadena.at(i) == ' ') numEspacios++ ;
        }
        if (numEspacios > 11) cout << "SALIDA NULA" << endl;
        else if (numEspacios == 11) cout << "CORRECTO" << endl;
        else cout << "TARDE" << endl;
    }    
}