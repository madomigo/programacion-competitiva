#include <iostream>
using namespace std;

int main() {
    int numCasos;
    cin >> numCasos;

    int barra, factor, tiempo;
    for (int i = 0; i < numCasos; i++) {
        cin >> barra >> factor >> tiempo;
        cout << tiempo % (barra + 1) * factor << "\n";
    }
}