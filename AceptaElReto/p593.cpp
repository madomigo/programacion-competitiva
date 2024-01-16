/**
* Pruebas en lotes
* Es el ejercicio 593 de Acepta el reto
* @author Marcos Dominguez y Mateo Domínguez
* @version 9.12.2021
*/

#include <iostream>
#include <string>
using namespace std;

/* Creamos variables globales, para que puedan ser editadas dentro de funciones sin problemas */
int nPersonas;
string muestras;
int nPruebas = 0;

void hacerTest (int pos1, int pos2) {
    nPruebas++;                                 // Si hemos entrado aquí, significa que hemos hecho una prueba
    /* Solamente si vamos a hacer la prueba a más de una persona */
    if (pos1 != pos2) {

        bool positivo = false;                  // Al comienzo, no hay ningún positvo

        /* Recorremos la parte del string que estamos evaluando */
        for (int i = pos1; i <= pos2; i++) {

            /* Si hay un positivo, no hace falta comprobar más,
            ya que todo ese lote ya está "infectado" */
            if (muestras[i] == '1') {
                positivo = true;
                break;
            }
        }

        int numPersonas = pos2 - pos1 + 1;
        int mitad = numPersonas / 2;
        if (numPersonas % 2 == 0) {
            mitad--;
        }

        /* Solamente si ha habido algún positvo en el grupo evaludado, hacemos dos pruebas,
        una a cada mitad del grupo que acabamos de evaluar */
        if (positivo) {
            hacerTest(pos1, pos1 + mitad);
            hacerTest(pos1 + mitad + 1, pos2);
        }
    }
}

int main() {
    while (true) {
        cin >> nPersonas;

        if (nPersonas == 0) break;

        nPruebas = 0;                                        // Reinicio el número de pruebas hechas en cada caso     

        cin >> muestras;

        hacerTest(0, nPersonas - 1);    // Llamo al método para calcular el número de pruebas que se necesitan

        cout << nPruebas << endl;
        
    }
    return 0;
}

