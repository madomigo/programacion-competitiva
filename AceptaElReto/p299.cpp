/**
* Pavimentar Barro City
* Es el ejercicio 299 de Acepta el reto
* @author Marcos Dominguez y Mateo Dominguez
* @version 28/01/2022
*
* Los comentarios no llevan tildes ni ñs, para evitar problemas con el editor de texto.
*/

#include <iostream>
#include <array>
#include <queue>
using namespace std;

/* Definimos la estructura de una calle. Representa el punto de orignen, hasta donde te lleva y cuanto te cuesta moverte. */
struct Calle {
    int calle, coste;

    Calle () {};

    Calle (int clle, int cste) {
        calle = clle;
        coste = cste;
    }

    /* Establecemos nuestro propio criterio de ordenacion. En este caso, como la priority_queue nos ordena los elementos de mayor a menor, ordenamos al reves */
    bool operator< (const Calle& Calle2) const {
        return (coste > Calle2.coste);
    }
};

vector<Calle> grafo [10001];
bool visitados[10001];

int prim () {
    priority_queue<Calle> cola;
    cola.push(Calle(1, 0));
    int coste = 0;

    Calle calle;
    while (!cola.empty()) {
        calle = cola.top();
        cola.pop();

        if (visitados[calle.calle]) continue;

        coste += calle.coste;
        visitados[calle.calle] = true;

        Calle c;
        for (int i = 0; i < grafo[calle.calle].size(); i++) {
            c = grafo[calle.calle][i];
            if (!visitados[c.calle]) cola.push(c);
        }
    }

    return coste;
}

int main() {
    int nPuntos, nCalles;       // Representa el numero de puntos que queremos conectar, y el numero de conexiones (o "calles") que tenemos, respectivamente.

    while(cin >> nPuntos >> nCalles) {

        /* Inicializamos el array */
        for (int i = 0; i <= nPuntos; i++) {
            visitados[i] = false;
            grafo[i].clear();
        }

        priority_queue<Calle> cola;     // Declaramos nuestra priority_queue
        
        int desde, hasta, coste;        // Informacion sobre la calle que estamos analizando

        /* Recogemos la entrada, y la metemos a la cola */
        for (int i = 0; i < nCalles; i++) {
            cin >> desde >> hasta >> coste;
            
            grafo[desde].push_back(Calle(hasta, coste));
            grafo[hasta].push_back(Calle(desde, coste));
        }




        int costeTotal = prim();             // Indica cuanto nos ha costado conectar las calles

        bool imposible = false;
        for (int i = 1; i <= nPuntos && !imposible; i++) {
            if (!visitados[i]) imposible = true;
        }

        if (!imposible) cout << costeTotal << '\n';
        else cout << "Imposible\n";
    }
}