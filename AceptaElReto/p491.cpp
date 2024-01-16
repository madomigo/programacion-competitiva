#include <iostream>
using namespace std;

int peso, numUvas;
int uvas[25];

int VueltaAtras(int i, int uva, int ocupado) {
    
    if (uva == 12 && ocupado <= peso) {
        return 1;
    }
    if (ocupado > peso || i == numUvas) {
        return 0;
    }

    return VueltaAtras(i + 1, uva + 1, ocupado + uvas[i]) + VueltaAtras(i + 1, uva, ocupado);
}

int main () {
    while (true) {
        cin >> peso >> numUvas;

        if (peso == 0 && numUvas == 0) break;

        for (int i = 0; i < numUvas; i++) {
            cin >> uvas[i];
        }
        cout << VueltaAtras(0, 0, 0) << "\n";

    }
}