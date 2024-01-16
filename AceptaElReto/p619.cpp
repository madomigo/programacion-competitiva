#include <iostream>
#include <map>
using namespace std;

char element;
char imagen[48][48];
bool sePuede(int fila, int col){
    map<char, int> count;
    for (int i = fila; i < fila + 8; i++) {
        for (int j = col; j < col + 8; j++) {
            //cout << "Estoy en: " << i << " " << j << "\n";
            //cout << "Anadido: " << element << "\n";
            
            
            if (count.size() > 2) {
                //cout << "Falso en: " << i << " " << j << "\n";
                return false;
            }
            element = imagen[i][j];
            if (count.find(element) == count.end()) {
                count[element] = 1;
            }
            else count[element]++;
        }
    }
    return count.size() < 3;
}


int main () {
    int ancho, alto;
    while (true) {
        cin >> ancho >> alto;

        if (ancho == 0 && alto == 0) break;

        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                cin >> imagen[i][j];
            }
            
        }

        bool puede = true;

        for (int i = 0; i < alto && puede; i += 8) {
            for (int j = 0; j < ancho && puede; j += 8) {
                puede = sePuede(i, j);
            }
        }

        if (puede) cout << "SI\n";
        else cout << "NO\n";

    }
}