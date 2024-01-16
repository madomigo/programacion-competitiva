#include <iostream>
using namespace std;

int maxCD(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }

    return maxCD (num2, num1 % num2);
}

int main () {
    while (true) {
        int comensales;
        cin >> comensales;

        if (comensales == 0) break;
        
        int numerador[comensales];
        int denominador[comensales];

        for (int i = 0; i < comensales; i++) {
            cin >> numerador[i];

            getchar();

            cin >> denominador[i];
        }

        int MCM = denominador[0];

        for (int i = 1; i < comensales; i++) {
            MCM = denominador[i] / maxCD(MCM, denominador[i]) * MCM ;
        }
        
        int suma = 0;
        for (int i = 0; i < comensales; i++) {
            suma += MCM / denominador[i] * numerador[i];
        }

        cout << MCM - suma << "\n";

    }
}