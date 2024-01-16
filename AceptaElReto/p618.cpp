#include <iostream>
#include <array>
using namespace std;

void resolver(int cinta[], int izq, int der) {
    int sum = 0;
    if (izq < der) {
        for (int i = izq + 1; i < der; i++) {
            sum += cinta[i];
        }
    }
    else {
        for (int i = izq; i >= der; i--) {
            sum -= cinta[i];
        }
    }
    cout << sum << "\n";
}


int main () {
    int niveles;
    while (true) {
        cin >> niveles;

        if (niveles == 0) break;

        int cinta[niveles];

        for (int i = 0; i < niveles; i++) {
            cin >> cinta[i];
        }

        int consultas;
        cin >> consultas;

        int izq, der;
        for (int i = 0; i < consultas; i++) {
            cin >> izq >> der;
            resolver(cinta, izq - 1, der - 1);
        }

        cout << "---\n";
    }
}