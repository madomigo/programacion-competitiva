/**
* Liga de pádel
* Es el ejercicio 109 de Acepta el reto
* @author Mateo Dominguez
* @version 3.12.2021
*/

#include <iostream>
#include <map>
#include <math.h>
using namespace std;

int main() {
    while(true) {
        string categoria;
        cin >> categoria;

        if (categoria == "FIN") break;

        string equipo1;
        string equipo2;
        int marcador1;
        int marcador2;
        int partidosJugados = 0;
        bool ganaEquipo1;
        map<string, int> resultados;

        while(true){
            cin >> equipo1;
            if (equipo1 == "FIN") break;
            partidosJugados++;
            cin >> marcador1;
            cin >> equipo2;
            cin >> marcador2;

            if (marcador1 > marcador2) ganaEquipo1 = true;
            else ganaEquipo1 = false;

            if (resultados.find(equipo1) == resultados.end()) {
                resultados[equipo1] = ganaEquipo1 ? 2 : 1;
            }
            else {
                resultados[equipo1] += ganaEquipo1 ? 2 : 1;
            }
            if (resultados.find(equipo2) == resultados.end()) {
                resultados[equipo2] = ganaEquipo1 ? 1 : 2;
            }
            else {
                resultados[equipo2] += ganaEquipo1 ? 1 : 2;
            }
        }
        string ganador;
        int puntosMax = 0;
        for (auto it = resultados.begin(); it != resultados.end(); it++) {
            if (it -> second > puntosMax) {
                ganador = it -> first;
                puntosMax = it -> second;
            }
            else if (it -> second == puntosMax) {
                ganador = "EMPATE";
            }
        }
        int nEquipos = resultados.size();
        cout << ganador << " " << nEquipos * (nEquipos - 1) - partidosJugados <<endl;
    }






}