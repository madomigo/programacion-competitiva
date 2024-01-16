#include <bits/stdc++.h>
using namespace std;


struct Camino {

    int calle;     // Indica la calle a la que nos dirigimos
    int coste;      // Indica cuanto nos cuesta reaccionar hasta clickar en la pagina + el tiempo que tarde en cargar

    Camino () {};

    Camino (int p, int c) {
        calle = p;
        coste = c;
    }

    bool operator< (const Camino &camino2) const {
        return (camino2.coste < coste);
    }
};

int numIntersecciones;             // Indica el numero de intersecciones que tenemos    
int numCalles;                   // Indica el numero de calles que tenemos
int veces[10001];

vector<Camino> grafo [10001];
int cuantoCuesta [10001];    // Indica cuanto nos cuesta llegar hasta cada calle


/* Aplicamos el algoritmo de dijkstra */
void dijkstra () {
    cuantoCuesta[1] = 0;    // Ir al punto 1 no nos cuesta nada
    veces[1] = 1;

    priority_queue<Camino> cola;
    cola.push(Camino(1, 0));


    Camino camino;
    while (!cola.empty()) {

        /* Analizamos la primera calle de la cola y lo borramos */
        camino = cola.top();
        cola.pop();


        /* Si lo que nos cuesta utilizar este enlace es menor o igual a lo que ya teniamos, quizas nos interese */
        if (camino.coste <= cuantoCuesta[camino.calle]) {

            /* Recorremos todas las paginas hasta las que podemos llegar desde este punto */
            for (auto c : grafo[camino.calle]) {
                /* Si lo que nos cueste este punto (mas el coste del que venimos) es menor a lo que ya teniamos, establecemos un nuevo minimo*/
                if (c.coste + camino.coste < cuantoCuesta[c.calle]) {
                    
                    /* Actualizamos el nuevo coste y metemos a la cola */
                    cuantoCuesta[c.calle] = c.coste + camino.coste;
                    cola.push(Camino(c.calle, cuantoCuesta[c.calle]));
                    veces[c.calle] = veces[camino.calle];
                }
                
                /* Si no, sumamos el minimo de antes */
                else if (c.coste + camino.coste == cuantoCuesta[c.calle]) {
                    veces[c.calle] += veces[camino.calle];
                }
            }
        }
    }
}


int main() {
    while (cin >> numIntersecciones) {


        for (int i = 1; i <= numIntersecciones; i++) {
            /* Reiniciamos el grafo y los costes de cada punto */
            grafo[i].clear();
            cuantoCuesta[i] = INT32_MAX;
            veces[i] = 0;
        }



        cin >> numCalles;
        int desde, hasta, tiempo;

        for (int i = 0; i < numCalles; i++) {
            /* Recogemos la entrada */
            cin >> desde >> hasta >> tiempo;

            /* Y la metemos al grafo. Anadimos al coste lo que tarde en cargar. EN AMBOS SENTIDOS */
            grafo[desde].push_back(Camino(hasta, tiempo));
            grafo[hasta].push_back(Camino(desde, tiempo));
        }


        dijkstra();


        cout << veces[numIntersecciones] << '\n';
    }
}