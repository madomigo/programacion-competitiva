#include <iostream>
using namespace std;

int main () {

    int nMedidas;
    while (true) {
        cin >> nMedidas;
        if (nMedidas == 0) break;

        int medida1, medida2, suma, maxAviso;
        suma = maxAviso = 0;
        cin >> medida1;
        if (medida1 <= 4) suma ++;
        for (int i = 1; i < nMedidas; i++) {
            cin >> medida2;

            if (medida2 <= 4 && (maxAviso > 6 || suma == 0)) {
                suma++;
                maxAviso = 0;
            }
            else {
                if (medida2 > maxAviso) maxAviso = medida2;
            }
        }

        cout << suma << endl;

    }
}