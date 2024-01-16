#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <limits>
#include <queue>
#include <map>
using namespace std;

int main () {
    int casas;

    while (true) {
        cin >> casas;

        if (casas == 0) break;


        int calle[casas];

        int escuchan = 0;

        for (int i = 0; i < casas; i++) {
         cin >> calle[i];
        }

        int sonido = 0;

        for (int i = casas - 1; i >= 0; i--) {
            if (sonido > 0) {
                escuchan++;
            }
            
            sonido--;
            
            sonido = max(sonido, calle[i]);

        }

        cout << escuchan << "\n";
    }
}