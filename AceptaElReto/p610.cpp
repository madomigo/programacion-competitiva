#include <iostream>
#include <vector>

using namespace std;

int main () {
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; i++) {
        int poblacion, iron, spi, eliminar, salto, elegido;
        cin >> poblacion >> iron >> spi >> salto;

        eliminar = poblacion / 2;
        if (poblacion % 2 == 1) eliminar++;

        vector<int> circulo;

        for (int j = 0; j < poblacion; j++) {
            if (j == iron - 1) circulo.push_back(1);
            else if (j == spi - 1) circulo.push_back(2);
            else circulo.push_back(0);
        }

        elegido = 0;
        
        while (circulo.size() > poblacion - eliminar) {
            elegido = (elegido + salto) % circulo.size();
            circulo.erase(circulo.begin() + elegido);
        }

        bool estaIron, estaSpi;
        estaIron = estaSpi = false;

        for (int j = 0; j < circulo.size(); j++) {
            if (circulo[j] == 1) estaIron = true;
            else if (circulo[j] == 2) estaSpi = true;
        }

        if (estaIron && !estaSpi) {
            cout << "No quiero irme, Sr. Stark!" << "\n";
        }
        else if (estaSpi && !estaIron) {
            cout << "No quiero irme, Peter!" << "\n";
        }
        else cout << "No hay abrazo" << "\n";




    }
}