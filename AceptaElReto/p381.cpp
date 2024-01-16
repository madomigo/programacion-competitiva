#include <iostream>
using namespace std;

int planetas, periodo, multiplo;

int MCD (int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }

    return MCD (num2, num1 % num2);
}

int main () {
    while (true) {
        cin >> planetas;


        if (planetas == 0) break;


        cin >> multiplo;

        for (int i = 1; i < planetas; i++) {
            cin >> periodo;
            multiplo = multiplo * periodo / MCD(multiplo, periodo);
        }

        cout << multiplo << "\n";

    }
}